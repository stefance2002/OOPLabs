#include<iostream>
#include<cstring>
using namespace std;

class NBAPlayer
{
protected:
    char *ime;
    char tim[40];
    double pts, ass, reb;
public:
    NBAPlayer(char *i="", char *t="", double p=0, double a=0, double r=0)
    {
        ime=new char[strlen(i)+1];
        strcpy(ime, i);
        strcpy(tim, t);
        pts=p;
        ass=a;
        reb=r;
    }
    NBAPlayer(const NBAPlayer &n)
    {
        ime=new char[strlen(n.ime)+1];
        strcpy(ime, n.ime);
        strcpy(tim, n.tim);
        pts=n.pts;
        ass=n.ass;
        reb=n.reb;
    }
    NBAPlayer &operator=(const NBAPlayer &n)
    {
        if(this!=&n)
        {
            ime=new char[strlen(n.ime)+1];
            strcpy(ime, n.ime);
            strcpy(tim, n.tim);
            pts=n.pts;
            ass=n.ass;
            reb=n.reb;
        }
        return *this;
    }
    ~NBAPlayer()
    {
        delete []ime;
    }
    double rating()
    {
        return (0.45*pts+0.3*ass+0.25*reb);
    }
    void print()
    {
        cout<<ime<<" - "<<tim<<endl;
        cout<<"Points: "<<pts<<endl;
        cout<<"Assists: "<<ass<<endl;
        cout<<"Rebounds: "<<reb<<endl;
        cout<<"Rating: "<<rating()<<endl;
    }
};

class AllStarPlayer : public NBAPlayer
{
private:
    double Apts, Aass, Areb;
public:
    AllStarPlayer(char *i="", char *t="", double p=0, double a=0, double r=0, double ap=0, double aa=0, double ar=0):NBAPlayer(i, t, p, a, r)
    {
        Apts=ap;
        Aass=aa;
        Areb=ar;
    }
    AllStarPlayer(NBAPlayer &n, double p, double a, double r) : NBAPlayer(n)
    {
        Apts=p;
        Aass=a;
        Areb=r;
    }
    AllStarPlayer(const AllStarPlayer &a):NBAPlayer(a)
    {
        Apts=a.Apts;
        Aass=a.Aass;
        Areb=a.Areb;
    }
    AllStarPlayer &operator=(const AllStarPlayer &a)
    {
        if(this!=&a)
        {
            NBAPlayer::operator=(a);
            Apts=a.Apts;
            Aass=a.Aass;
            Areb=a.Areb;
        }
        return *this;
    }
    ~AllStarPlayer()
    {

    }
    double allStarRating()
    {
        return(0.3*Apts+0.4*Aass+0.3*Areb);
    }
    double rating()
    {
        double a=NBAPlayer::rating();
        return ((a+allStarRating())/2);
    }
    void print()
    {
        NBAPlayer::print();
        cout<<"All Star Rating: "<<allStarRating()<<endl;
        cout<<"New Rating: "<<rating()<<endl;
    }
};

int main() {
  char name[50];
  char team[40];
  double points;
  double assists;
  double rebounds;
  double allStarPoints;
  double allStarAssists;
  double allStarRebounds;

  NBAPlayer * players = new NBAPlayer[5];
  AllStarPlayer * asPlayers = new AllStarPlayer[5];
  int n;
  cin >> n;

  if (n == 1) {

    cout << "NBA PLAYERS:" << endl;
    cout << "=====================================" << endl;
    for (int i = 0; i < 5; ++i) {
      cin >> name >> team >> points >> assists >> rebounds;
      players[i] = NBAPlayer(name,team,points,assists,rebounds);
      players[i].print();
    }
  }
  else if (n == 2) {

    for (int i=0; i < 5; ++i){
      cin >> name >> team >> points >> assists >> rebounds;
      cin >> allStarPoints >> allStarAssists >> allStarRebounds;
      players[i] = NBAPlayer(name,team,points,assists,rebounds);
      asPlayers[i] = AllStarPlayer(players[i],allStarPoints,allStarAssists,allStarRebounds);
    }

    cout << "NBA PLAYERS:" << endl;
    cout << "=====================================" << endl;
    for (int i=0; i < 5; ++i)
      players[i].print();

    cout << "ALL STAR PLAYERS:" << endl;
    cout << "=====================================" << endl;
    for (int i=0; i < 5; ++i)
      asPlayers[i].print();

    }
    else if (n == 3) {

      for (int i=0; i < 5; ++i){
        cin >> name >> team >> points >> assists >> rebounds;
        cin >> allStarPoints >> allStarAssists >> allStarRebounds;
        asPlayers[i] = AllStarPlayer(name, team, points, assists, rebounds,
                                     allStarPoints,allStarAssists,allStarRebounds);
      }
      cout << "ALL STAR PLAYERS:" << endl;
      cout << "=====================================" << endl;
      for (int i=0; i < 5; ++i)
        asPlayers[i].print();

    }

    delete [] players;
    delete [] asPlayers;
}
