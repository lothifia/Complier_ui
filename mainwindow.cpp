#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <vector>
#include "head.h"
#include "yacc.h"
#ifdef __cplusplus
extern "C" {
#endif
    void init();
    void redirectInput(FILE *input);
    void displaytable();
    void listall();
    void interpret();
    int base(int l, int* s, int b);
    int yyparse();
    int y_main(char* fname);

#ifdef __cplusplus
}
#endif

int b; /* 指令基址 */
int t; /* 栈顶指针 */
int p;
int s[stacksize];	/* 栈 */
int pre_p;
QColor white, blue;

void listall_2(std::vector<QString>& a)
{
    int i;
    char name[][5]=
    {
        {"lit"},{"opr"},{"lod"},{"sto"},{"cal"},{"int"},{"jmp"},{"jpc"},
    };
    for (i = 0; i < cx; i++)
   {	QString sp;
        sp.sprintf("%d %s %d %d\n", i, name[code[i].f], code[i].l, code[i].a);
        a.emplace_back(sp);
    }
}

FILE* open1 = NULL;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    lock = 0;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_pa1_clicked()
{
    if(!lock){
         ui->list1_pcd->clear();
        char fn[] = "tp.txt";
        if((open1 = fopen(fn, "w")) == NULL)
        {
            printf("open file error!\n");
            exit(1);
        }
        QString qs;
        QString res_l = "";
        qs = ui->text1->toPlainText();
        fprintf(open1, "%s", qs.toStdString().c_str());
        fclose(open1);
        int tem = y_main(fn);

        ui->list1_stk->clear();
        for(int i = 0; i < t + 1; i++){
            QString tem;
            tem.sprintf("p %d: %d", i, s[i]);
            ui->list1_stk->insertItem(i, tem);
        }

        QFile file("fresult.txt");
              if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                  return;

              QTextStream in(&file);
              QString line = in.readLine();
              while (!line.isNull()) {
                  res_l += line + "\n";
                  line = in.readLine();
              }
              ui->text1_out->setText(res_l);

         std::vector<QString> pc_l;
         listall_2(pc_l);
         for(int i = 0; i < pc_l.size(); i++){
            ui->list1_pcd->insertItem(i, pc_l[i]);
         }
         QString bug_l = "";
         QFile file_bug("fbug.txt");
               if (!file_bug.open(QIODevice::ReadOnly | QIODevice::Text))
                   return;

               QTextStream in_bug(&file_bug);
               QString line_bug = in_bug.readLine();
               while (!line_bug.isNull()) {
                   bug_l += line_bug + "\n";
                   line_bug = in_bug.readLine();
               }
               ui->text1_bug->setText(bug_l);
    }else{
        QMessageBox msgb;
        msgb.setText("one steping can not run");
        msgb.exec();
    }
}
int MainWindow::interpret_2(int p)
{
    QString tem_str;
    QString pre_str = ui->text1_out->toPlainText();
    struct instruction i;	/* 存放当前指令 */
        i = code[p];	/* 读当前指令 */
        p = p + 1;
        switch (i.f)
        {
            case lit:	/* 将常量a的值取到栈顶 */
                t = t + 1;
                s[t] = i.a;
                break;
            case opr:	/* 数学、逻辑运算 */
                switch (i.a)
                {
                    case 0:  /* 函数调用结束后返回 */
                        t = b - 1;
                        p = s[t + 3];
                        b = s[t + 2];
                        t -= i.l;
                        printf("return to t: %d p: %d b: %d \n *******\n", t, p, b);

                        break;
                    case 1: /* 栈顶元素取反 */
                        s[t] = - s[t];
                        break;
                    case 2: /* 次栈顶项加上栈顶项，退两个栈元素，相加值进栈 */
                        t = t - 1;
                        s[t] = s[t] + s[t + 1];
                        break;
                    case 3:/* 次栈顶项减去栈顶项 */
                        t = t - 1;
                        s[t] = s[t] - s[t + 1];
                        break;
                    case 4:/* 次栈顶项乘以栈顶项 */
                        t = t - 1;
                        s[t] = s[t] * s[t + 1];
                        break;
                    case 5:/* 次栈顶项除以栈顶项 */
                        t = t - 1;
                        s[t] = s[t] / s[t + 1];
                        break;
                    case 6:/* 栈顶元素的奇偶判断 */
                        s[t] = s[t] % 2;
                        break;
                    case 8:/* 次栈顶项与栈顶项是否相等 */
                        t = t - 1;
                        s[t] = (s[t] == s[t + 1]);
                        break;
                    case 9:/* 次栈顶项与栈顶项是否不等 */
                        t = t - 1;
                        s[t] = (s[t] != s[t + 1]);
                        break;
                    case 10:/* 次栈顶项是否小于栈顶项 */
                        t = t - 1;
                        s[t] = (s[t] < s[t + 1]);
                        break;
                    case 11:/* 次栈顶项是否大于等于栈顶项 */
                        t = t - 1;
                        s[t] = (s[t] >= s[t + 1]);
                        break;
                    case 12:/* 次栈顶项是否大于栈顶项 */
                        t = t - 1;
                        s[t] = (s[t] > s[t + 1]);
                        break;
                    case 13: /* 次栈顶项是否小于等于栈顶项 */
                        t = t - 1;
                        s[t] = (s[t] <= s[t + 1]);
                        break;
                    case 14:/* 栈顶值输出 */
                        if(i.l == 0){
                            printf("%d", s[t]);
                            tem_str.sprintf("%d \n",s[t]);
                            t = t - 1;
                        }else if(i.l > 0){
                            memset(buffer, 0, sizeof(buffer));
                            for(int ii = 0; ii < i.l; ii++){
                                printf("t is %d s[t]: %d \n", t ,s[t]);
                                buffer[i.l - ii - 1] = s[t];
                                t = t - 1;
                            }
                            printf("here output %s", buffer);
                            tem_str.sprintf("%s \n", buffer);
                        }else if(i.l == -1){

                            char c = s[t];
                            t = t - 1;
                            printf("%c", c);
                            tem_str.sprintf("%c \n", c);
                        }
                        pre_str += tem_str;
                        ui->text1_out->setText(pre_str);
                        break;
                    case 15:/* 输出换行符 */
                        printf("\n");
                        break;
                    case 16:/* 读入一个输入置于栈顶 */
                        if(i.l == 0){
                            t = t + 1;
                            printf("?");
                            scanf("%d", &(s[t]));
                        }else{
                            printf("? (need a string)");
                            scanf("%s", buffer);
                            printf("i.l %d, t %d \n", i.l, t);
                            for(int cnt_i = 0; cnt_i < i.l; cnt_i++){
                                printf("t %d, buffer %d \n", t, buffer[cnt_i]);
                                t = t + 1;
                                s[t] = buffer[cnt_i];
                            }
                        }

                        break;

                }
                break;
            case lod:	/* 取相对当前过程的数据基地址为a的内存的值到栈顶 */
                if(i.l < 0){
                    t = t + 1;
                    s[t] = s[0];
                }
                else if(i.l == 0 && i.a == 0){
                    s[t - 2] = s[base(s[t],s, b) + s[t - 1] + s[t - 2]];
                    t = t - 2;
                }else if(i.l >0 && i.a > 0){
                    t = t + 1;
                    s[t] = s[base(i.l, s, b) + i.a];
                }else{
                    t = t + 1;
                    s[t] = s[base(i.l,s,b) + i.a];
                }
                    printf("t is %d,lod at : %d  + %d ,%d \n",t ,base(i.l, s, b), i.a, s[base(i.l, s,b) + i.a]);
                break;
            case sto:	/* 栈顶的值存到相对当前过程的数据基地址为a的内存 */
                if(i.l < 0 && i.a != 0){
                    s[b + i.a] = s[b + i.l];
                    printf("wa!!\n");
                    printf("i.l = %d, i.a = %d\n", i.l, i.a);
                }else if(i.l < 0 && i.a == 0){
                    s[0] = s[t];
                    printf("s[0] is %d \n", s[0]);
                }else if(i.l == 0 && i.a == 0){
                    s[base(s[t - 1], s, b) + s[t - 2] + s[t - 3]] = s[t];
                    t = t - 4;
                }else if(i.l > 0 && i.a == 0){
                    s[base(s[t], s, b) + s[t - 1] + s[t - 2]] = s[t - 2 - i.l + s[t - 2]];
                    printf("t is %d,sto at : %d,  %d , %d \n",
                            t,
                            base(s[t], s, b) + s[t - 1] + s[t - 2],
                            s[t - 2],
                            s[t - 2 - i.l + s[t - 2]]);
                    t = t - 3;
                }else{
                    s[base(i.l, s, b) + i.a] = s[t];
                    t = t - 1;
                }
                    /* printf("t is %d,sto at : %d  + %d , %d \n",t ,base(i.l, s, b), i.a, s[b  + i.a]); */
                break;
            case cal:	/* 调用子过程 */
                printf("now call , t at %d\n", t);
                s[t + 1] = base(i.l, s, b);	/* 将父过程基地址入栈，即建立静态链 */
                s[t + 2] = b;	/* 将本过程基地址入栈，即建立动态链 */
                s[t + 3] = p;	/* 将当前指令指针入栈，即保存返回地址 */
                b = t + 1;	/* 改变基地址指针值为新过程的基地址 */
                p = i.a;	/* 跳转 */
                printf("t: %d p: %d b: %d \n *******\n", t, p, b);
                break;
            case ini:	/* 在数据栈中为被调用的过程开辟a个单元的数据区 */
                t = t + i.a;qDebug()<<"here"<<endl;
                printf("ini t is %d\n", t);
                break;
            case jmp:	/* 直接跳转 */
                p = i.a;
                break;
            case jpc:	/* 条件跳转 */
                if (s[t] == 0)
                    p = i.a;
                t = t - 1;
                break;
        }
    return p;
}


void MainWindow::on_p_start_clicked()
{
    if(!lock){
        ui->text1_out->setText("start one step\n");
        b = 1; /* 指令基址 */
        t = 0; /* 栈顶指针 */
        p = 0;
        pre_p = 0;
        lock = 1;
        white.setRgb(255,255,255);
        blue.setRgb(0,255,255);
        ui->list1_pcd->item(p)->setBackgroundColor(blue);
        s[0] = 0; /* s[0]不用 */
        s[1] = 0; /* 主程序的三个联系单元均置为0 */
        s[2] = 0;
        s[3] = 0;
    }else{
        QMessageBox msgb;
        msgb.setText("you are in one step");
        msgb.exec();
    }
}

void MainWindow::on_p_ostep_clicked()
{
    if(lock){
        ui->list1_pcd->item(p)->setBackgroundColor(white);
        p = interpret_2(p);
        ui->list1_pcd->item(p)->setBackgroundColor(blue);
        ui->list1_stk->clear();
        for(int i = 0; i < t + 1; i++){
            QString tem;
            tem.sprintf("p %d: %d", i, s[i]);
            ui->list1_stk->insertItem(i, tem);
        }

        if(p == 0)
        {
            QMessageBox msgb;
            msgb.setText("one step finish");
            msgb.exec();
            lock = 0;
            ui->text1_out->setText(ui->text1_out->toPlainText() + "finish one step \n");

        }
    }
    else{
        QMessageBox msgb;
        msgb.setText("you are not in one step");
        msgb.exec();
    }
}
