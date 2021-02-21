#include<stdio.h>
struct dosen{
    char dcode[35];
    char dname[35];
    char dgender[15];
    int num;
}a[105];

struct student{
    char scode[35];
    char sname[35];
    char sgender[15];
    char father[35];
    char mother[35];
    int sibling;
}b[105];

int main(){
    int x;
    int y;
    scanf("%d", &x);
    for(int i = 1;i<=x;i++){
        scanf("\n%s",a[i].dcode);
        scanf("\n%[^\n]",a[i].dname);
        scanf("\n%[^\n]",a[i].dgender);
        scanf("%d",&a[i].num);
        for(int j = 1;j<=a[j].num;j++){
            scanf("\n%s",b[j].scode);
            scanf("\n%[^\n]",b[j].sname);
            scanf("\n%[^\n]",b[j].sgender);
            scanf("\n%[^\n]",b[j].father);
            scanf("\n%[^\n]",b[j].mother);
            scanf("%d",&b[j].sibling);
        }
        scanf("%d", &y);
    }
    printf("Kode Dosen: %s\n",a[y].dcode);
    printf("Nama Dosen: %s\n",a[y].dname);
    printf("Gender Dosen: %s\n",a[y].dgender);
    printf("Jumlah Mahasiswa: %d\n",a[y].num);
    for(int i =0;i<a[y].num;i++){
        printf("Kode Mahasiswa: %s\n",b[i].scode);
        printf("Nama Mahasiswa: %s\n",b[i].sname);
        printf("Gender Mahasiswa: %s\n",b[i].sgender);
        printf("Nama Ayah: %s\n",b[i].father);
        printf("Nama Ibu: %s\n",b[i].mother);
        printf("Jumlah Saudara Kandung: %d\n",b[i].sibling);
    }
    return 0;
}
