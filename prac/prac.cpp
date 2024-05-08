#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int const N=100000;
vector<int>graph[N];
int ar[N];
int mod=1000000007;
signed main(){
	// cout<<"you : ";
	// string s;cin>>s;
	vector<pair<string,vector<string>>>rescont;
	map<string,vector<string>>mp;
	vector<string>v={"yo","hi","hello","hey","issue","glitch","registerquery","createticket","reportissue","unabletologin","frozenaccount","loginissue","cannotmakepayment","transactionproblem","paymentissue","productinformation","features","specifications","needinfo","tellmedetails","stillthere","notresolving","stuckthere","stillnotworking","yes","unabletoresolve","needassistance","contactadmin","thankyou","no","leaveit","bye","goodbye"};
	for(int i=0;i<v.size();i++){
		if(v[i]=="hello" | v[i]=="hey"){
			vector<string>res;
			res.push_back("Hello! Welcome to our customer support. How can I assist you today?");
			res.push_back("Hi there! How can I help you?");
			rescont.push_back({v[i],res});
			mp[v[i]]=res;
		}
		else if(v[i]=="issue"| v[i]=="glitch"| v[i]=="registerquery"|v[i]=="createticket"|v[i]=="reportissue"){
			vector<string>res;
			res.push_back("Sure, I can help you with that. Please describe your issue.");
			rescont.push_back({v[i],res});
			mp[v[i]]=res;
		}
		else if(v[i]=="unabletologin" | v[i]=="frozenaccount"|v[i]=="loginissue"){
			vector<string>res;
			res.push_back("Please make sure you are using the correct username and password. If the issue persists, try resetting your password.");
			rescont.push_back({v[i],res});
			mp[v[i]]=res;
		}
		else if(v[i]=="cannotmakepayment" | v[i]=="transactionproblem"|v[i]=="paymentissue"){
			vector<string>res;
			res.push_back("I apologize for the inconvenience. Please provide details of the transaction so we can investigate.");
			rescont.push_back({v[i],res});
			mp[v[i]]=res;
		}
		else if(v[i]=="stillthere" | v[i]=="notresolving"|v[i]=="stuckthere" | v[i]=="stillnotworking" | v[i]=="yes" | v[i]=="unabletoresolve"| v[i]=="needassistance"|v[i]=="contactadmin"){
			vector<string>res;
			res.push_back("I am sorry for the inconvenience. Let me escalate your issue to our administration. They will reach out to you soon. Can I help you with anything else!!");
			rescont.push_back({v[i],res});
			mp[v[i]]=res;
		}
		else if(v[i]=="productinformation" | v[i]=="features" |v[i]=="specifications"| v[i]=="needinfo" | v[i]=="tellmedetails"){
			vector<string>res;
			res.push_back("You can find detailed product information on our website or user manual. If you need specific details, feel free to ask.");
			rescont.push_back({v[i],res});
			mp[v[i]]=res;
		}
		else if(v[i]=="thankyou"){
			vector<string>res;
			res.push_back("You\'re welcome!', 'Anytime!', 'Glad I could assist you.");
			rescont.push_back({v[i],res});
			mp[v[i]]=res;
		}
		else if(v[i]=="leaveit" | v[i]=="bye" | v[i]=="goodbye"){
			vector<string>res;
			res.push_back("Thank you for reaching out. Have a great day!', 'Goodbye! Take care.");
			rescont.push_back({v[i],res});
			mp[v[i]]=res;
		}
	}
	int x=0;
	while(true){
		if(x>0) break;
		cout<<"you : ";
		string s;
		getline(cin,s);
		string ns="";
		for(int i=0;i<s.size();i++){
			if(s[i]!=' ') ns+=tolower(s[i]);
		}
		// cout<<ns<<endl;
		int cnt=0;

		for(auto i : mp){
			string f = i.first;
			vector<string>dm =i.second;
			if(ns.find(f)!=string::npos){
				cnt++;
				cout<<"chatbot : "<<dm[0]<<endl;
				if(f=="no" | f=="leaveit" | f=="bye" | f=="goodbye"){
					x++;
				}
				break;
			}
		}

		if(cnt==0){
			cout<<"chatbot : "<<"I'm sorry, It's outside my capacity. Would you like to speak with our administration?"<<endl;
			x++;
		}
	}
	return 0;
}



/*you : hello
chatbot : Hello! Welcome to our customer support. How can I assist you today?                                                                                                       
you : I am facing issue with my account
chatbot : Sure, I can help you with that. Please describe your issue.                                                                                                               
you : I am unable to login
chatbot : Please make sure you are using the correct username and password. If the issue persists, try resetting your password.                                                     
you : i am having payment issue
chatbot : Sure, I can help you with that. Please describe your issue.                                                                                                               
you : cannot make payment
chatbot : I apologize for the inconvenience. Please provide details of the transaction so we can investigate.                                                                       
you : thank you
chatbot : You're welcome!', 'Anytime!', 'Glad I could assist you.                                                                                                                   
you : bye
chatbot : Thank you for reaching out. Have a great day!', 'Goodbye! Take care.  */