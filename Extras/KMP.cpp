vector<int> prefix_function(string s) 
{
    int n = s.size();
    vector<int> lps(n);
    int i=0, j=0;

    for (i=1; i<n; i++) 
    {
        j = lps[i-1];
        
        while (j>0 && s[i]!=s[j])
            j = lps[j-1];
        
        if (s[i]==s[j])
            j++;
        
        lps[i] = j;
    }
    return lps;
}