int l=0,r=n;
while(r-l>1)
{
    int mid= l + (r-l)/2;
    if(check(mid)) l=mid;
    else r=mid;
}
if(check(r)) l=r;
return l;
