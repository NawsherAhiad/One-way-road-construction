

#include <bits/stdc++.h>
using namespace std;
int white=0,grey=1,black=2;
vector <int> sortedNodes;
vector <int> adj[500005];
vector <int> adjrev[500005];
int color[500005];
int n, e;

const int mx = 500005;
int in[mx], out[mx];
int indx=0;

vector <int> SCCs[500005];


void dfs(int u)
{
    color[u]=grey;
    int v;
    for(int i=0; i<adj[u].size(); i++)
    {
        v=adj[u][i];
        if(color[v]==white)
            dfs(v);
    }
    color[u]=black;
    sortedNodes.push_back(u);
}



void dfsrev(int u)
{
    color[u]=grey;
    int v;
    for(int i=0; i<adjrev[u].size(); i++)
    {
        v=adjrev[u][i];
        if(color[v]==white)
            dfsrev(v);
    }
    color[u]=black;
    SCCs[indx].push_back(u);



}

int main()
{
    int u, v;
    int cnt =0;
    cin>>n>>e;
    for(int i=0; i<e; i++)
    {
        cin>>u>>v;
        in[v]++;
        out[u]++;
        adj[u].push_back(v);
        adjrev[v].push_back(u);
    }

    for(int i=1; i<=n; i++)
    {
        color[i]=white;
    }
    for(int i=1; i<=n; i++)
    {
        if(color[i]==white)
        {
            dfs(i);

        }
    }
    reverse(sortedNodes.begin(), sortedNodes.end());

    for(int i=1; i<=n; i++)
    {
        color[i]=white;
    }

    for(int i=0; i<sortedNodes.size(); i++)
    {
        if(color[sortedNodes[i]]==white)
        {
            dfsrev(sortedNodes[i]);

            indx++;
        }
    }


    int S_in[n],S_out[n];

    for(int i=0; i<n; i++)
    {
        S_in[i]=0;
        S_out[i]=0;

    }
    int insum=0,outsum=0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<SCCs[i].size(); j++)
        {
            insum+=in[SCCs[i][j]] ;
            outsum+=out[SCCs[i][j]];
            S_in[i]=insum;
            S_out[i]=outsum;
        }

        insum=0;
        outsum=0;
    }

///ok thik ase


///DAG wise node count

    int node_count[indx];

    for(int i=0; i<indx; i++)
    {
        node_count[i]=0;
    }


    for(int i=0; i<indx; i++)
    {
        node_count[i]=SCCs[i].size();
    }

    /*cout<<"node count: ";
    for(int i=0;i<indx;i++)
    {
        cout<<node_count[i]<<" ";
    }
    */
    int S_in2[n],S_out2[n];
    for(int i=0; i<indx; i++)
    {
        S_in2[i]=999999;
        S_out2[i]=999999;
    }


    int c=0,x=0;
    for(int i=0; i<indx; i++)
    {
        x=SCCs[i].size();
        //cout<<"Sixe" <<x;
        if(x==1)
        {
            c++;
        }

    }
   // cout<<"c"<<c<<endl;

    if(c==n)
    {
       for(int i=0; i<indx; i++)
        {
            S_in2[i]=S_in[i];

            S_out2[i]=S_out[i];

        }

    }
    else
    {

         for(int i=0; i<indx; i++)
        {
            S_in2[i]=abs(node_count[i] - S_in[i] );

            S_out2[i]=abs(node_count[i] - S_out[i] );

        }
    }




   /* cout<<"DAG in and out :"<<endl;
    for(int i=0; i<indx; i++)
    {
        cout<<S_in2[i]<<" "<<S_out2[i]<<endl;
    }
*/

    for(int j=0; j<indx; j++)
    {
        if(S_in2[j]>1)
        {
            S_in2[j]=1;
        }

        if(S_out2[j]>1)
        {
            S_out2[j]=1;
        }
    }




    int in_count =0;
    int out_count = 0;
    for(int i=0; i<indx; i++)
    {
        in_count+=S_in2[i];
        out_count+=S_out2[i];
    }


    int ans=max(indx-in_count,indx-out_count);

    if(ans==1)
    {
        cout<<"1"<<endl;
    }
    else
    {
        cout<<"0"<<endl;
    }



    return 0;



}

