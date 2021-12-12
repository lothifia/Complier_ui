#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
//int main(){
//    printf("Input file        ");
//    scanf("%s", fname);
//    if((fin = fopen(fname, "r")) == NULL)
//    {
//        printf("open file error!\n");
//        exit(1);
//    }
//    /* if ((foutput = fopen("foutput.txt", "w")) == NULL)
//    {
//		printf("Can't open the output file!\n");
//		exit(1);
//	}
//	if ((ftable = fopen("ftable.txt", "w")) == NULL)
//	{
//		printf("Can't open ftable.txt file!\n");
//		exit(1);
//	}
//    */
//    redirectInput(fin);
//    init();

//    yyparse();
//    displaytable();
//    listall();
//    interpret();
//    fclose(fin);
//    /* fclose(ftable);
//    fclose(foutput);
//    */
//    return 0;
//}

