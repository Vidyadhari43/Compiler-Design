#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter no.of production rules: ";
    cin >> n;
    cin.ignore();  

    vector<string> production_rules(n, "");
    cout << "Enter Production Rules:" << endl;

    for (int i = 0; i < n; i++) {
        getline(cin, production_rules[i]);
    }

    vector<string> lhs;
    vector<string> rhs;

    for (int i = 0; i < n; i++) {
        bool exist=false;
        char* word=&production_rules[i][0];
        char* token = strtok(word, "->");
        for(int j=0;j<lhs.size();j++){
            if(lhs[j]==token){
                exist=true;
                token = strtok(NULL, "->");
                rhs[j]=rhs[j]+"|"+token;
            }
        }
        if(!exist){
            lhs.push_back(token);
            token = strtok(NULL, "->");
            rhs.push_back(token);
        }
    }

    n=lhs.size();
    vector<vector<string>>pr(n);
    for(int i=0;i<n;i++){
        string s="";
        for(auto c:rhs[i]){
            if(c=='|'){
                pr[i].push_back(s);
                s="";
            }
            else if(c==' '){
                continue;
            }
            else{
                s=s+c;
            }
        }
        if(s!=""){
            pr[i].push_back(s);
        }
    }
    map<string,vector<string>>mp;
    for(int i=0;i<pr.size();i++){
        sort(pr[i].begin(),pr[i].end());
        string nt=lhs[i];
        string com_prefix="";
        int start_index=-1;
        bool comm_exist=false;
        for(int j=0;j<pr[i].size();j++){
            if(com_prefix==""){
                com_prefix=pr[i][j];
                start_index=j;
            }
            else{
                int n1=com_prefix.size();
                int n2=pr[i][j].size();
                int x=0,y=0;
                while(x<n1 && y<n2){
                    if(com_prefix[x]!=pr[i][j][y]){
                        break;
                    }
                    ++x;++y;
                }
                if(x>0){
                    com_prefix=com_prefix.substr(0,x);
                    comm_exist=true;
                }
                else{
                    int count=j-start_index;
                    if(count>1){
                        lhs.push_back(nt+"1'");
                        mp[lhs[i]].push_back(com_prefix+nt+"1'");
                        nt=nt+"'";
                        vector<string>temp;
                        for(int k=start_index;k<j;k++){
                            temp.push_back(pr[i][k].substr(com_prefix.size(),pr[i][k].size()-com_prefix.size()));
                        }
                        pr.push_back(temp);
                    }
                    else{
                        mp[lhs[i]].push_back(pr[i][start_index]);
                    }
                    com_prefix=pr[i][j];
                    start_index=j;
                }
            }
        }
        if(!comm_exist){
            mp[lhs[i]]=pr[i];
        }
        else if(com_prefix!=""){
            int count=pr[i].size()-start_index;
            if(count>1){
                lhs.push_back(nt+"1'");
                mp[lhs[i]].push_back(com_prefix+nt+"1'");
                nt=nt+"'";
                vector<string>temp;
                for(int k=start_index;k<pr[i].size();k++){
                    temp.push_back(pr[i][k].substr(com_prefix.size(),pr[i][k].size()-com_prefix.size()));
                }
                pr.push_back(temp);
            }
            else{
                mp[lhs[i]].push_back(pr[i][start_index]);
            }
        }
    }
    
    cout<<"\nOutput:"<<endl;
    for(auto pa:mp){
        cout<<pa.first<<" -> ";
        for(string s:pa.second){
            if(s==""){
                cout<<"epsilon | ";
            }
            else{
                cout<<s<<" | ";
            }
        }
        cout<<endl;
    }
    return 0;
}
