#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

float gpmaker(int,int,int);
float gpmaker1(int,int);
float gpmaker2(int,int,int);
float gpmaker3(int,int);
float gpmaker4(int,int);
float gpmaker5(int);
const char * capitalize(char *str);

int cls,stdnum,i;
char section[20],filename[20],sch[50],d[5];
FILE *p,*p1,*p2,*p3,*p4,*p5,*p6,*p7,*p8,*p9,*p10,*p11,*p12,*p13,*p14,*out,*n,*s;




int main()
{



    //s=fopen("setting.txt","r");
    //fscanf(s,"School:%[^\n]\nClass:%d\nSection:%s\nNumber of Students:%d",sch,&cls,section,&stdnum);

    printf("\t\t\tWelcome to Digital result system");

    printf("\nSchool: ");
    gets(sch);
    printf("Class: ");
    scanf("%d",&cls);
    printf("Section: ");
    scanf("%s",section);
    printf("Number of Students: ");
    scanf("%d",&stdnum);

    printf("\nSchool: %s\nClass: %d\nSection: %s\nNumber of Students: %d",sch,cls,section,stdnum);
    printf("\nAre all informations right? Type 'yes' or 'no'? ");
    scanf("%s",d);
    if(strcmp(strlwr(d),"yes")==0) {

    stdnum++;


    int bang1[stdnum][2],bang2[stdnum][2],eng1[stdnum][2],eng2[stdnum][2],islam[stdnum][2],bgs[stdnum][2],gmath[stdnum][2];
    int phy[stdnum][3],chem[stdnum][3],comp[stdnum][3],opt[stdnum][3],agri[stdnum][2],ict[stdnum][2],sci[stdnum][2];

    int total[stdnum],count=0;
    float gp[stdnum][10],gpa[stdnum];
    char name[stdnum][30];

    p1=fopen("bangla1.csv","r");
    p2=fopen("bangla2.csv","r");
    p3=fopen("english1.csv","r");
    p4=fopen("english2.csv","r");
    p5=fopen("islam.csv","r");
    p6=fopen("bgs.csv","r");
    p7=fopen("gmath.csv","r");
    //p8=fopen("physics.csv","r");
    //p9=fopen("chemistry.csv","r");
    //p10=fopen("compalsary.csv","r");
    //p11=fopen("optional.csv","r");
    p12=fopen("homeeconomics.csv","r");
    p13=fopen("ict.csv","r");
    p14=fopen("science.csv","r");
    n=fopen("name.csv","r");

    for(i=1;i<stdnum;i++)
    {
        fscanf(p1,"%d,%d",&bang1[i][0],&bang1[i][1]);
        fscanf(p2,"%d",&bang2[i][0]);
        fscanf(p3,"%d",&eng1[i][0]);
        fscanf(p4,"%d",&eng2[i][0]);
        fscanf(p5,"%d,%d",&islam[i][0],&islam[i][1]);
        fscanf(p6,"%d,%d",&bgs[i][0],&bgs[i][1]);
        fscanf(p7,"%d,%d",&gmath[i][0],&gmath[i][1]);
        //fscanf(p8,"%d,%d,%d",&phy[i][0],&phy[i][1],&phy[i][2]);
        //fscanf(p9,"%d,%d,%d",&chem[i][0],&chem[i][1],&chem[i][2]);
        //fscanf(p10,"%d,%d,%d",&comp[i][0],&comp[i][1],&comp[i][2]);
        //fscanf(p11,"%d,%d,%d",&opt[i][0],&opt[i][1],&opt[i][2]);
        fscanf(n,"%[^\n]\n",name[i]);
        fscanf(p12,"%d,%d",&agri[i][0],&agri[i][1]);
        fscanf(p13,"%d,%d",&ict[i][0]);
        fscanf(p14,"%d,%d",&sci[i][0],&sci[i][1]);
    }
    printf("\nCollecting marks..........\nplease wait.....");
    Sleep(5000);


    for(i=1;i<stdnum;i++)
    {
        gp[i][1]=gpmaker(bang1[i][0],bang1[i][1],bang2[i][0]);
        gp[i][2]=gpmaker4(eng1[i][0],eng2[i][0]);
        gp[i][3]=gpmaker1(islam[i][0],islam[i][1]);
        gp[i][4]=gpmaker1(bgs[i][0],bgs[i][1]);
        gp[i][5]=gpmaker1(gmath[i][0],gmath[i][1]);
        //gp[i][6]=gpmaker2(phy[i][0],phy[i][1],phy[i][2]);
        //gp[i][7]=gpmaker2(chem[i][0],chem[i][1],chem[i][2]);
        //gp[i][8]=gpmaker2(comp[i][0],comp[i][1],comp[i][2]);
        //gp[i][9]=gpmaker2(opt[i][0],opt[i][1],opt[i][2])-2.00;
        gp[i][6]=gpmaker1(agri[i][0],agri[i][1]);
        gp[i][7]=gpmaker5(ict[i][0]);
        gp[i][8]=gpmaker1(sci[i][0],sci[i][1]);
        if(gp[i][1]==0.0||gp[i][2]==0.0||gp[i][3]==0.0||gp[i][4]==0.0||gp[i][5]==0.0||gp[i][6]==0.0||gp[i][7]==0.0||gp[i][8]==0.0) gpa[i]=0.0;
        else gpa[i]=(gp[i][1]+gp[i][2]+gp[i][3]+gp[i][4]+gp[i][5]+gp[i][6]+gp[i][7]+gp[i][8])/8.00;
        total[i]=bang1[i][0]+bang1[i][1]+bang2[i][0]+eng1[i][0]+eng2[i][0]+islam[i][0]+islam[i][1]+bgs[i][0]+bgs[i][1]+gmath[i][0]+gmath[i][1]+agri[i][0]+agri[i][1]+ict[i][0]+sci[i][0]+sci[i][1];
    }
    out=fopen("Result_sheet.csv","w");
    fprintf(out,"Roll,Name,Bangla,English,Islam,BGS,General math,Science,Home economics,ICT,Total,GPA\n");
    for(i=1;i<stdnum;i++)
    {
        fprintf(out,"%d,%s,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%d,%.2f\n",i,capitalize(name[i]),gp[i][1],gp[i][2],gp[i][3],gp[i][4],gp[i][5],gp[i][8],gp[i][6],gp[i][7],total[i],gpa[i]);
    }
    printf("\nGPA calculating.......");
    Sleep(5000);


    for(i=1;i<stdnum;i++)
    {
        sprintf(filename,"./Mark_sheet/roll%d.txt",i);
        p=fopen(filename,"w");
        fprintf(p,"   %s\n   Class: %d\tSection: %s\n\n   Name: %s\n   Roll: %d",sch,cls,section,name[i],i);
        fprintf(p,"\n\nSubjects\t\tMark\t\tGrade point\n--------\t\t------\t\t--------------");
        fprintf(p,"\n1. Bangla\t\t%d\t\t%.2f",bang1[i][0]+bang1[i][1]+bang2[i][0],gp[i][1]);
        fprintf(p,"\n2. English\t\t%d\t\t%.2f",eng1[i][0]+eng2[i][0],gp[i][2]);
        fprintf(p,"\n3. Islam\t\t%d\t\t%.2f",islam[i][0]+islam[i][1],gp[i][3]);
        fprintf(p,"\n4. BGS\t\t\t%d\t\t%.2f",bgs[i][0]+bgs[i][1],gp[i][4]);
        fprintf(p,"\n5. General math\t\t%d\t\t%.2f",gmath[i][0]+gmath[i][1],gp[i][5]);
        fprintf(p,"\n6. Science\t\t%d\t\t%.2f",sci[i][0]+sci[i][1],gp[i][8]);
        fprintf(p,"\n7. Home economics\t%d\t\t%.2f",agri[i][0]+agri[i][1],gp[i][6]);
        fprintf(p,"\n8. ICT\t\t\t%d\t\t%.2f",ict[i][0],gp[i][7]);
        //fprintf(p,"\n9. Optional\t\t%d\t\t%.2f(%.2f)",opt[i][0]+opt[i][1]+opt[i][2],gp[i][9]+2,gp[i][9]);
        fprintf(p,"\n--------------------------------------------------");
        fprintf(p,"\n\t\tTotal: %d\t\tGPA: %.2f",total[i],gpa[i]);
        fprintf(p,"\n\n\n\n\n-----------------------------------------\n       Signature of Head Teacher\n(%s)",sch);
        fclose(p);

    }
    printf("\nFinishing.....\nplease wait....");
    Sleep(5000);
    printf("\n\nResult sheet & mark sheet of individual students are created successfully.");
    for(i=1;i<=stdnum;i++)
    {
        if(gpa[i]==0.0) count++;
    }
    printf("\n\nResult summary: \nPass: %d\nFail:%d",stdnum-count-1,count);
    printf("\nThank you for using this program\n-Farhan Tanvir Hridoy,M.D.,UDVASHITO MUKH,ME-17,BUET");

    getch();
    }
    else printf("\nRun the Program Again!");
    fclose(out);
    getch();


}


float gpmaker(int a,int b,int c)
{
    int e;

    e=a+b+c;
    if(e>=150*0.8) return 5.00;
    else if(e>=150*0.7) return 4.00;
    else if(e>=150*0.6) return 3.50;
    else if(e>=150*0.5) return 3.00;
    else if(e>=150*0.4) return 2.00;
    else if(e>=150*0.33) return 1.00;
    else return 0.00;

}
float gpmaker1(int a,int b)
{
    int e;

    e=a+b;
    if(e>=80) return 5.00;
    else if(e>=70) return 4.00;
    else if(e>=60) return 3.50;
    else if(e>=50) return 3.00;
    else if(e>=40) return 2.00;
    else if(e>=33) return 1.00;
    else return 0.00;

}
float gpmaker2(int a,int b,int c)
{
    int e;
    if(a<17||b<9||c<9) return 0.00;
    else
    {
        e=a+b+c;
        if(e>=80) return 5.00;
        else if(e>=70) return 4.00;
        else if(e>=60) return 3.50;
        else if(e>=50) return 3.00;
        else if(e>=40) return 2.00;
        else if(e>=33) return 1.00;
        else return 0.00;
    }
}
float gpmaker3(int a,int b)
{
    int e;
    if(a<33||b<33) return 0.00;
    else
    {
        e=a+b;
        if(e>=160) return 5.00;
        else if(e>=140) return 4.00;
        else if(e>=120) return 3.50;
        else if(e>=100) return 3.00;
        else if(e>=80) return 2.00;
        else if(e>=66) return 1.00;
        else return 0.00;
    }
}
float gpmaker4(int a,int b)
{
    int e;

    e=a+b;
    if(e>=150*0.8) return 5.00;
    else if(e>=150*0.7) return 4.00;
    else if(e>=150*0.6) return 3.50;
    else if(e>=150*0.5) return 3.00;
    else if(e>=150*0.4) return 2.00;
    else if(e>=150*0.33) return 1.00;
    else return 0.00;

}
float gpmaker5(int a)
{
    int e;

    e=a;
    if(e>=25*0.8) return 5.00;
    else if(e>=25*0.7) return 4.00;
    else if(e>=25*0.6) return 3.50;
    else if(e>=25*0.5) return 3.00;
    else if(e>=25*0.4) return 2.00;
    else if(e>=25*0.33) return 1.00;
    else return 0.00;

}
const char * capitalize(char *str)
{
    int length, i;
    length = strlen(str);

  for(int i=0;i<length;i++)
  {
      if(i==0) //Conerting character at first and last index to uppercase.
      {
          str[i]=toupper(str[i]);
      }
      else if(str[i]==' ')//Conerting characters present before and after space to uppercase.
      {

          str[i+1]=toupper(str[i+1]);

      }
      else if(str[i]==',') str[i] = ' ';
  }
  return str;
}



