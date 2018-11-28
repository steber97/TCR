
class mycomparison{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const pair<int, int> & lhs, const pair<int, int> &rhs) const{
    // Custom comparison operator among two arbitrary objects, in this case a pair.
    if (reverse) return (lhs.second>rhs.second);
    else return (lhs.second<rhs.second);
  }
};

typedef priority_queue<pair<int, int> ,vector<pair<int, int> >, mycomparison> mypq_type;

mypq_type q1;       // Max priority queue (extracts in order 6, 4, 2)
mypq_type q1(mycomparison(true));          // Min priority queue (extracts in order (2, 4, 6))