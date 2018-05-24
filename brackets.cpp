#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * Complete the function below.
 */
vector < string > Braces(vector < string > values) {
    int countleft[3];
    // initialize countleft
    for(int i=0; i<3; i++){
        countleft[i]=0;
    }
    
    // initialize a vector of string
    int vsize=values.size();
    vector <string> result;
    
    for(int i=0; i<vsize; i++){
    /*	if((values.at(i).compare(1,1,"]")) || (values.at(i).compare(1,1,")")) || (values.at(i).compare(1,1,"}"))){
            cout<<"compared first char of string"<<endl;
	    result.push_back("NO");
            continue;
    }*/
	int check = 0;
	int sleng=values[i].length();
        for(int j=0; j<sleng; j++){
            if(values.at(i).compare(j,1,"{")){
                countleft[0]=countleft[0]+1;
		/*if(values.at(i).compare(j+1,1,"}")){
                    countleft[0]=countleft[0]-1;
                    cout<<"the countleft 1 is "<<countleft[0]<<endl;
                    j++;
                }*/


                if((values.at(i).compare(j+1,1,")")) || (values.at(i).compare(j+1,1,"]"))){
                    cout<<"wrong: { is followed by ) or ]"<<endl;
                    result.push_back("NO");
                    countleft[0]=0;
                    check = 1;
                    break;
                }
                else if(values.at(i).compare(j+1,1,"}")){
                    countleft[0]=countleft[0]-1;
                    cout<<"the countleft 1 is "<<countleft[0]<<endl;
                    j++;
		}
            }
            else if(values.at(i).compare(j,1,"(")){
                countleft[1]=countleft[1]+1;
		/*if(values.at(i).compare(j+1,1,")")){
                     countleft[1]=countleft[1]-1;
                     cout<<"the countleft 2 is "<<countleft[1]<<endl;
                     j++;
                }*/

		if((values.at(i).compare(j+1,1,"}")) || (values.at(i).compare(j+1,1,"]"))){
                    cout<<"wrong: ( is followed by } or ]"<<endl;
                    result.push_back("NO");
                    countleft[1]=0;
                    check = 1;
                    break;
                }
                else if(values.at(i).compare(j+1,1,")")){
                    countleft[1]=countleft[1]-1;
                    cout<<"the countleft 2 is "<<countleft[1]<<endl;
                    j++;
                }
		/*else{
		 j++;
		 continue;
		}*/
		
            }
            else if(values.at(i).compare(j,1,"[")){
                countleft[2]=countleft[2]+1;
		/*if(values.at(i).compare(j+1,1,"]")){
                    countleft[2]=countleft[2]-1;
                    cout<<"the countleft 3 is "<<countleft[2]<<endl;
                    j++;
                }*/
		
		if((values.at(i).compare(j+1,1,")")) || (values.at(i).compare(j+1,1,"}"))){
                    result.push_back("NO");
                    cout<<"wrong: [ is followed by ) or }"<<endl;
                    countleft[2]=0;
                    check = 1;
                    break;
                    
                }
                else if(values.at(i).compare(j+1,1,"]")){
                    countleft[2]=countleft[2]-1;
                    cout<<"the countleft 3 is "<<countleft[2]<<endl;
                    j++;
                }
		/*else{
			j++;
			continue;
		}*/
            }
	// Missing cases of right brackets
	//
          else if(values.at(i).compare(j,1,"}")){
	  	countleft[0]=countleft[0]-1;
		j++;
	  }
	  else if(values.at(i).compare(j,1,")")){
	  	countleft[1]=countleft[1]-1;
		j++;
	  }	
	  else if(values.at(i).compare(j,1,"]")){
		countleft[2]=countleft[2]-1;
		j++;
	  }
	}
        cout<<countleft[0]<<" ";
	cout<<countleft[1]<<" ";
	cout<<countleft[2]<<" "<<endl;
        if((countleft[0] == 0) && (countleft[1] == 0) && (countleft[2]==0) && check == 0){
            result.push_back("YES");
            continue;
        }
        else if(check == 1){
            continue;
        }
        else result.push_back("NO");
    }
    return result;
}

int main(void){
//	ofstream fout(getenv("OUTPUT_PATH"));
	vector <string> res;
	
	int valsize=0;
	cout<<"Enter the value size:"<<endl;
	cin>>valsize;
	if(valsize < 0) cout<<"error: negative size"<<endl;
	
	cin.ignore(1000,'\n');
	string vitem;
	vector <string> values;
	cout<<"Enter the strings:"<<endl;
	for(int i=0; i<valsize; i++){
		getline(cin, vitem);
		values.push_back(vitem);
	}
	
	res=Braces(values);
	cout<<"The result of the braces:"<<endl;
	int res_size=res.size();
	for(int res_i=0; res_i<res_size; res_i++){
		cout<<res[res_i]<<endl;
	}
	
	return 0;
}
