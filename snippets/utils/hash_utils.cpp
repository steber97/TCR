struct key_hash : public unary_function<vector<int>, size_t>
{
    size_t operator()(const vector<int> & k) const
    {
        int res = 0;
        for (int i = 0; i<N; i++){
            res ^= k[i];
        }
        return res;
    }
};

struct key_equal : public binary_function< vector<int>,  vector<int>, bool>
{
   bool operator()(const  vector<int> & v0, const  vector<int>& v1) const
   {
        for (int i = 0; i<N; i++){
            if (v0[i] != v1[i])
            return false;
        }
        return true;
   }
};
