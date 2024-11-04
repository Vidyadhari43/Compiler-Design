#include <bits/stdc++.h>
using namespace std;

char epsilon=char(-18);
char new_nt='A';
unordered_map<char,int>mp_nt;

void resolve_non_immediate_left_recur(int x,int y,vector<string>&lhs,vector<vector<string>>&pr){
    // cout<<x<<" "<<y<<" non_immediate_left_recur func\n";
    vector<string> s_new;
    for(int i=0;i<pr[x].size();i++){
        int n=pr[x][i].size();
        int m=lhs[y].size();
        string comp=pr[x][i].substr(0,m);
        if(comp==lhs[y]){
            for(int j=0;j<pr[y].size();j++){
                comp=pr[y][j]+(pr[x][i].substr(m,n-m));
                s_new.push_back(comp);
            }
        }
        else{
            s_new.push_back(pr[x][i]);
        }
    }
    pr[x]=s_new;
    
}
void solve_immediate_left_recur(int in,vector<string>&lhs,vector<vector<string>>&pr){
    // cout<<in<<" immediate left recursion func\n";
    sort(pr[in].begin(),pr[in].end());
    string nt=lhs[in];
    vector<string> alpha;
    vector<string> beta;
    int n=nt.size();
    for(int i=0;i<pr[in].size();i++){
        string substr_check=pr[in][i].substr(0,n);
        if(substr_check==nt){
            alpha.push_back(pr[in][i].substr(n,pr[in][i].size()-n));
        }
        else{
            beta.push_back(pr[in][i]);
        }
    }
    if(alpha.size()==0 || beta.size()==0){
        return;
    }
    pr[in].clear();
    while(mp_nt[new_nt]>0){
        new_nt++;
    }
    mp_nt[new_nt]++;
    for(int i=0;i<beta.size();i++){
        // pr[in].push_back(beta[i]+nt+"'");
        pr[in].push_back(beta[i]+new_nt);
    }
    // lhs.push_back(nt+"'");
    string new_nonterminal;
    new_nonterminal+=new_nt;
    lhs.push_back(""+new_nonterminal);
    //push corresponding production rule
    for(int i=0;i<alpha.size();i++){
        // alpha[i]=alpha[i]+nt+"'";
        alpha[i]=alpha[i]+new_nt;
    }
    string add;
    add+=epsilon;
    alpha.push_back(add);
    // cout<<add<<" "<<beta.size()<<endl;
    pr.push_back(alpha);
}
void left_recursion(vector<string>&lhs, vector<vector<string>>&pr){
    // cout<<"left recursion func\n";
    int len=lhs.size();
    for(int i=0;i<len;i++){
        mp_nt[lhs[i][0]]++;
    }
    for(int i=0;i<len;i++){
        for(int j=0;j<i;j++){
            resolve_non_immediate_left_recur(i,j,lhs,pr);
        }
        solve_immediate_left_recur(i,lhs,pr);
    }
}

int main(){
    vector<string>lhs;
    vector<vector<string>>pr;
    lhs.push_back("E");pr.push_back({"E+T","T"});
    lhs.push_back("T");pr.push_back({"T*F","F"});
    lhs.push_back("F");pr.push_back({"(E)","i"});
    // lhs.push_back("A");pr.push_back({"Aa","b"});
    left_recursion(lhs,pr);
    // cout<<"over\n";
    for(int i=0;i<lhs.size();i++){
        cout<<lhs[i]<<" -> ";
        for(int j=0;j<pr[i].size();j++){
            cout<<pr[i][j]<<" | ";
        }
        cout<<"\n";
    }
    return 0;
}