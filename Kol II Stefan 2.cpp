#include<iostream>
#include<cstring>
using namespace std;

class MediaSegment
{
protected:
    char title[100];
    char author[100];
    int size;
    int duration;
public:
    MediaSegment(const char *t="", const char *a="", int d=0, int s=0)
    {
        strcpy(title, t);
        strcpy(author, a);
        size=s;
        duration=d;
    }
    virtual double price()=0;
    char*getTitle()
    {
        return title;
    }
    char*getAuthor()
    {
        return author;
    }
};

class AudioRecording : virtual public MediaSegment
{
protected:
    short channels;
    short format;
public:
    AudioRecording(const char *t="", const char *a="", int d=0,
            int s=0, short f=0, short c=0):MediaSegment(t,a, d, s)
        {
            channels=c;
            format=f;
        }
    double price()
    {
        double a=duration*channels;
        if(format==3)
        {
            return a*1.5;
        }
        return a;
    }
    friend ostream &operator<<(ostream &out, AudioRecording&a)
    {
        out<<a.title<<" - "<<a.author<<" - "
        <<a.duration<<" - "<<a.size<<" - "<<a.price()<<endl;
        return out;
    }

};

class VideoRecording : virtual public MediaSegment
{
protected:
    int sirina, kompresija;
public:
    VideoRecording(const char *t="", const char *a="", int d=0,
            int s=0, int siri=0, int komp=0):MediaSegment(t,a, d, s)
        {
            sirina=siri;
            kompresija= komp;
        }
    double price()
    {
        double a=0;
        if(sirina<=1920)
        {
            a=duration*100;
        }
        else
        {
            a=duration*170;
        }
        if(kompresija==0)
        {
            return a*1.5;
        }
        else if(kompresija==1)
        {
            return a*0.9;
        }
        else
        {
            return a;
        }
    }
    friend ostream &operator<<(ostream &out, VideoRecording&a)
    {
        out<<a.title<<" - "<<a.author<<" - "<<a.duration<<
        " - "<<a.size<<" - "<<a.sirina<<" - "<<a.price()<<endl;
        return out;
    }
};

class MusicVideo : public AudioRecording, public VideoRecording
{
private:
    int datum;
public:
    MusicVideo(const char *t="", const char *a="", int d=0, int s=0,
               short f=0, short c=0, int siri=0, int komp=0, int data=0)
               :MediaSegment(t,a,d,s)
        {
            format=f;
            channels=c;
            siri=sirina;
            komp=kompresija;
            datum=data;
        }
    double price()
    {
        double a=AudioRecording::price()+VideoRecording::price();
        cout<<a<<endl;
        if(datum%10000>2010)
        {
            return a*1.3;
        }
        else
        {
            return a;
        }
    }
    friend ostream &operator<<(ostream &out,  MusicVideo&a)
    {
        out<<a.title<<" - "<<a.author<<" - "<<a.datum
        <<" - "<<a.duration<<" - "<<a.price()<<endl;
        return out;
    }
};

double total_price(MediaSegment**m, int n)
{
    double a=0;
    for(int i=0; i<n; i++)
    {
        a+=m[i]->price();
    }
    return a;
}
MusicVideo &cheapest_music_video(MediaSegment **zapis, int n)
{
    int najevtino = 0;
    int prvo = 1;
    for(int i = 0; i < n; i++)
    {
        MusicVideo *temp = dynamic_cast<MusicVideo*>(zapis[i]);
        if(temp && prvo)
        {
            najevtino = i;
            prvo = 0;
        }
        else if(temp)
        {
            if(zapis[i]->price() < zapis[najevtino]->price())
            {
                najevtino = i;
            }
        }
    }
    MusicVideo *temp = dynamic_cast<MusicVideo*>(zapis[najevtino]);
    return *temp;
}


using namespace std;
int main() {

  int test_case_num;
  cin>>test_case_num;
  // for MediaSegment
  char title[100];
  char author[1000];
  unsigned int size;
  unsigned int duration;
  // for AudioRecording
  //-------------------
  unsigned short channels;
  // AudioFormat:
  // 0 - mp3
  // 1 - wav
  // 2 - ogg
  // 3 - flac
  unsigned short format;
  // for VideoRecording
  //-------------------
  unsigned short width;
  // VideoCompression:
  // 0 - x264
  // 1 - Theor.
   // 2 - AV1
  int compression;
  // for MusicVideo
  //-------------------
  int publication_date;

  if (test_case_num == 1){
    cout<<"Testing class AudioRecording and operator<<"<<endl;
    cin.get();
    cin.getline(title,100);
    cin.getline(author, 100);
    //cin.get();
    cin >> duration >> size;
    cin >> format >> channels;

    AudioRecording a(title, author, duration, size, format, channels);

    cout<<a;

  }

  else if (test_case_num == 2){
    cout<<"Testing class VideoRecording and operator<<"<<std::endl;
    cin.get();
    cin.getline(title,100);
    cin.getline(author, 100);
    //cin.get();
    cin >> duration >> size;
    cin >> width >> compression;

    VideoRecording v(title, author, duration, size, width, compression);

    cout<<v;

  }

  else if (test_case_num == 3){
    cout<<"Testing class MusicVideo and operator<<"<<std::endl;

    cin.get();
    cin.getline(title,100);
    cin.getline(author, 100);
    //cin.get();
    cin >> duration >> size;

    cin >> format >> channels;
    cin >> width >> compression;

    cin>>publication_date;
    MusicVideo mv(title, author, duration, size, format, channels, width, compression, publication_date);

    cout << mv;
  }

  else if (test_case_num == 4){
    cout<<"Testing function: total_price "<<std::endl;

    MediaSegment ** m;

    int num_media_segments;
    cin >> num_media_segments;

    // 1 - AudioRecording
    // 2 - VideoRecording
    // 3 - MusicVideo
    short media_type;

    m = new MediaSegment*[num_media_segments];

    for (int i=0; i<num_media_segments; i++) {

      cin >> media_type;

      cin.get();
      cin.getline(title,100);
      cin.getline(author, 100);
      //cin.get();
      cin >> duration >> size;

      switch(media_type) {
      case 1:
              cin >> format >> channels;
              m[i] = new AudioRecording(title, author, duration, size, format, channels);
          break;
      case 2:
              cin >> width >> compression;
              m[i] = new VideoRecording(title, author, duration, size, width, compression);
          break;
      case 3:
              cin >> format >> channels;
              cin >> width >> compression;
              cin>>publication_date;
              m[i] = new MusicVideo(title, author, duration, size, format, channels, width, compression, publication_date);
          break;
      }
    }

    //for (int i=0;i<num_media_segments; i++){
    //    cout << *m[i];
    //}

    cout<< "Total price is: " << total_price(m, num_media_segments);

    delete [] m;

  }
  else if (test_case_num == 5){
    cout<<"Testing function: cheapest_music_video "<<std::endl;

    MediaSegment ** m;

    int num_media_segments;
    cin >> num_media_segments;

    // 1 - AudioRecording
    // 2 - VideoRecording
    // 3 - MusicVideo
    short media_type;

    m = new MediaSegment*[num_media_segments];

    for (int i=0; i<num_media_segments; i++) {

      cin >> media_type;

      cin.get();
      cin.getline(title,100);
      cin.getline(author, 100);
      //cin.get();
      cin >> duration >> size;

      switch(media_type) {
      case 1:
              cin >> format >> channels;
              m[i] = new AudioRecording(title, author, duration, size, format, channels);
          break;
      case 2:
              cin >> width >> compression;
              m[i] = new VideoRecording(title, author, duration, size, width, compression);
          break;
      case 3:
              cin >> format >> channels;
              cin >> width >> compression;
              cin>>publication_date;
              m[i] = new MusicVideo(title, author, duration, size, format, channels, width, compression, publication_date);
          break;
      }
    }

    cout << cheapest_music_video(m, num_media_segments);

    delete [] m;
  }

  return 0;
}
