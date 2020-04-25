
#include "header.h"
void ptype(struct stat dinfo);//输出文件类型
void pper(struct stat dinfo);//输出文件权限
void ptime(struct stat dinfo);//输出文件最后修改日期
void powner(struct dirent* dir);//输出文件名


void dir_test()
{
    DIR* dp;
    char pathname[255]; 
    getcwd(pathname, 255); //获取当前工作目录
    dp = opendir(pathname);
    if(dp == NULL)
    {
        printf("opne dir err\n");
        return;
    }
    struct dirent* d;
    struct stat dinfo;
    while((d = readdir(dp)) != NULL)
    {
       if(d->d_name[0] == '.')//跳过. .. 目录
       {
           continue;
       }
       stat(d->d_name, &dinfo);
       ptype(dinfo);
       pper(dinfo);
       ptime(dinfo);
       powner(d);
    }
    closedir(dp);
    return;
}

void ptype(struct stat dinfo)
{
    if(S_ISDIR(dinfo.st_mode))
    {
        printf("d");
    }else if (S_ISREG(dinfo.st_mode))
    {
        printf("-");
    }else if (S_ISFIFO(dinfo.st_mode))
    {
         printf("p");
    }else if (S_ISLNK(dinfo.st_mode))
    {
         printf("l");
    }else if (S_ISCHR(dinfo.st_mode))
    {
         printf("c");
    }else if (S_ISBLK(dinfo.st_mode))
    {
         printf("b");
    }else if (S_ISSOCK(dinfo.st_mode))
    {
         printf("s");
    }
}
void pper(struct stat dinfo)
{
    //判断文件所有者权限
    if((S_IRUSR&dinfo.st_mode) == S_IRUSR)
    {
        printf("r");
    }else{
        printf("-");
    }
    if((S_IWUSR&dinfo.st_mode) == S_IWUSR)
    {
        printf("w");
    }else{
        printf("-");
    }
    if((S_IXUSR&dinfo.st_mode) == S_IXUSR)
    {
        printf("x");
    }else{
        printf("-");
    }
    //判断组权限
    if((S_IRGRP&dinfo.st_mode) == S_IRGRP)
    {
        printf("r");
    }else{
        printf("-");
    }
    if((S_IWGRP&dinfo.st_mode) == S_IWGRP)
    {
        printf("w");
    }else{
        printf("-");
    }
    if((S_IXGRP&dinfo.st_mode) == S_IXGRP)
    {
        printf("x");
    }else{
        printf("-");
    }
    //判断其他权限
    if((S_IROTH&dinfo.st_mode) == S_IROTH)
    {
        printf("r");
    }else{
        printf("-");
    }
    if((S_IWOTH&dinfo.st_mode) == S_IWOTH)
    {
        printf("w");
    }else{
        printf("-");
    }
    if((S_IXOTH&dinfo.st_mode) == S_IXOTH)
    {
        printf("x ");
    }else{
        printf("- ");
    }


}
void ptime(struct stat dinfo)
{
    struct tm* ts;
    ts = localtime(&dinfo.st_mtime);
    
    printf("%d-%d-%d %d:%d:%d ", ts->tm_year+1900, ts->tm_mon+1, ts->tm_mday, ts->tm_hour, ts->tm_min, ts->tm_sec);

}
void powner(struct dirent* dir)
{
    printf("%s\n", dir->d_name);
}