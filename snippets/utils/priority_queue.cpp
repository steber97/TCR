
class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const pair<int, vector<int> >& lhs, const pair<int, vi>&rhs) const{
    if (reverse) return (lhs.first>rhs.first);
    else return (lhs.first<rhs.first);
  }
};

vector<int> myints = {1,2,3,4};
priority_queue<int,vector<int>,mycomparison> q1(mycomparison(true)); // greater than
priority_queue<int,vector<int>,mycomparison> q2; // less than
std::priority_queue<int, std::vector<int>, std::greater<int> >third (myints,myints+4);