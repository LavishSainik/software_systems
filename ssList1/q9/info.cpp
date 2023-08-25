#include<iostream>
using namespace std;
#include<sys/stat.h>
#include<ctime>

int main(){
    const char *filename = "what";
    struct stat fileStat;

    if( stat(filename,&fileStat) ==1 ){
       perror("Error");
       return 1;
    }


    cout<<"The name of file is  "<<filename<<endl;
    cout<<"The inode number of file is "<<fileStat.st_ino<<endl;
    cout<<"UID of file is " <<fileStat.st_uid<<endl;
    cout<<"Group ID of file is "<<fileStat.st_gid<<endl;
    cout<<"The size of file is "<<fileStat.st_size<<endl;
    cout<<"The block size of file is "<< fileStat.st_blksize<<endl;
    cout<<"The number of blocks in file is "<<fileStat.st_blocks<<endl;
    cout<<"Time of last access "<<ctime(&fileStat.st_atime)<<endl;
    cout<<"Time of last modification is "<< ctime(&fileStat.st_mtime)<<endl;
    cout<<"Time of last change is "<<ctime(&fileStat.st_ctime)<<endl;




return 0;}
