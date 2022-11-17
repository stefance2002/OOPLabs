#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Image
{
protected:
    char *ime;
    char sopstvenik[50];
    int sirina, dolzina;
public:
    Image(const char *i="untitled", const char *sops="unknown", int s=800, int d=800)
    {
        ime=new char[strlen(i)+1];
        strcpy(ime, i);
        strcpy(sopstvenik, sops);
        sirina=s;
        dolzina=d;
    }
    Image(const Image&im)
    {
        ime=new char[strlen(im.ime)+1];
        strcpy(ime, im.ime);
        strcpy(sopstvenik, im.sopstvenik);
        sirina=im.sirina;
        dolzina=im.dolzina;
    }
    virtual int fileSize()
    {
        return sirina*dolzina*3;
    }
    friend ostream&operator<<(ostream&out, Image&i)
    {
        out<<i.ime<<" "<<i.sopstvenik<<" "<<i.fileSize()<<endl;
        return out;
    }
};

class TransparentImage : public Image
{
private:
    bool transp;
public:
    TransparentImage(const char *i="untitled", const char *sops="unknown", int s=800, int d=800, bool t=false):Image(i, sops, s, d)
    {
        transp=t;
    }
    int fileSize()
    {
        if(transp)
        {
            return sirina*dolzina*4;
        }
        else
        {
            return sirina*dolzina+sirina*dolzina/8;
        }
    }
    friend ostream&operator<<(ostream&out, TransparentImage&i)
    {
        out<<i.ime<<" "<<i.sopstvenik<<" "<<i.fileSize()<<endl;
        return out;
    }
};

class Folder
{
private:
    char ime[255], sopstvenik[50];
    Image *sliki[100];
public:
    Folder(const char*i="", const char *sops="unknown", Image **s=0)
    {
        strcpy(ime, i);
        strcpy(sopstvenik, sops);
        sliki[0]=NULL;
    }
    int folderSize()
    {
        int sum=0;
        for(int i=0; sliki[i]!=NULL && i<100; i++)
        {
            sum+=sliki[i]->fileSize();
        }
        return sum;
    }
    Image *getMaxFile()
    {
        int maxx=0;
        for(int i=0; sliki[i]!=NULL && i<100; i++)
        {
            if(sliki[maxx]->fileSize()<sliki[i]->fileSize())
            {
                maxx=i;
            }
        }
        return sliki[maxx];
    }
    Folder &operator+=(Image &im)
    {
        int i=0;
        for(i=0; sliki[i]!=NULL && i<100; i++)
        {

        }
        sliki[i]=&im;
        sliki[i+1]=NULL;
    }
    friend ostream&operator<<(ostream&out, Folder f)
    {
        out<<f.ime<<" "<<f.sopstvenik<<endl<<"--"<<endl;
        for(int i=0; f.sliki[i]!=NULL && i<100; i++)
        {
            out<<*f.sliki[i];
        }
        out<<"--"<<endl<<"Folder size: "<<f.folderSize()<<endl;
    }
     Image* operator[](int n)
    {
        if(sliki[n])
        {
            return sliki[n];
        }
        return NULL;
    }
};

Folder max_folder_size(Folder *f, int n)
{
    int max=0;
    for(int i=0; i<n; i++)
    {
        if(f[i].folderSize()>f[max].folderSize())
        {
            max=i;
        }
    }
    return f[max];
}
int main() {

    int tc; // Test Case

    char name[255];
    char user_name[51];
    int w, h;
    bool tl;

    cin >> tc;

    if (tc==1){
      // Testing constructor(s) & operator << for class File

      cin >> name;
      cin >> user_name;
      cin >> w;
      cin >> h;


      Image f1;

      cout<< f1;

      Image f2(name);
      cout<< f2;

      Image f3(name, user_name);
      cout<< f3;

      Image f4(name, user_name, w, h);
      cout<< f4;
    }
    else if (tc==2){
      // Testing constructor(s) & operator << for class TextFile
      cin >> name;
      cin >> user_name;
      cin >> w >> h;
      cin >> tl;

      TransparentImage tf1;
      cout<< tf1;

      TransparentImage tf4(name, user_name, w, h, tl);
      cout<< tf4;
    }
    else if (tc==3){
      // Testing constructor(s) & operator << for class Folder
      cin >> name;
      cin >> user_name;

      Folder f3(name, user_name);
      cout<< f3;
    }
    else if (tc==4){
      // Adding files to folder
      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      Image * f;
      TransparentImage *tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }
      cout<<dir;
    }
    else if(tc==5){
      // Testing getMaxFile for folder

      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      Image* f;
      TransparentImage* tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }
      cout<< *(dir.getMaxFile());
    }
    else if(tc==6){
      // Testing operator [] for folder

      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      Image* f;
      TransparentImage* tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }

      cin >> sub; // Reading index of specific file
      cout<< *dir[sub];
    }
    else if(tc==7){
      // Testing function max_folder_size
      int folders_num;

      Folder dir_list[10];

      Folder dir;
      cin >> folders_num;

      for (int i=0; i<folders_num; ++i){
        cin >> name;
        cin >> user_name;
        dir = Folder(name, user_name);


        Image* f;
        TransparentImage *tf;

        int sub, fileType;

        while (1){
          cin >> sub; // Should we add subfiles to this folder
          if (!sub) break;

          cin >>fileType;
          if (fileType == 1){ // Reading File
            cin >> name;
            cin >> user_name;
            cin >> w >> h;
            f = new Image(name,user_name, w, h);
              dir += *f;
          }
          else if (fileType == 2){
            cin >> name;
            cin >> user_name;
            cin >> w >> h;
            cin >> tl;
            tf = new TransparentImage(name,user_name, w, h, tl);
              dir += *tf;
          }
        }
        dir_list[i] = dir;
      }

     cout<<max_folder_size(dir_list, folders_num);
    }
    return 0;
};
