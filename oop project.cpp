#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
class String_converter
{
protected:
	string text;
    	int i;
	int Alphabets=0,space=0;
public:
    	String_converter()
	{
        	text = "";
    	}
    	String_converter(string s)
    	{
      	set_value(s);
    	}
    	void set_value(string s)
    	{
        	text = s;
    	}
    	string get_value()
    	{
       	return text;
    	}  
 
    		friend void upper_to_lower(String_converter obj);
    		friend void lower_to_upper(String_converter obj);
   
    	void reverse(string str)
    	{
		string str1="";
		for(int i=str.size()-1;i>=0;--i)
		{
			str1+=str[i];
		}
			cout<<"\n The reversed string is  : "<< str1<<endl;
			cout<<endl;
			cout<<"                     --------------------"<<endl;
    	}
    
    
      void count_strings(string str)
	{
    		for(i=0; str[i] != '\0'; i++)
    		{
        
            	if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z')) 
            	{  
                		Alphabets++;
          		}
   
    			else if(str[i]==' ')
    			{
                		space++;
    			}
    			else{
        			cout<<"Count only alphabets and spaces"<<endl;
    			}
    	}
    	
    	cout<<endl;
    	cout<<"Alphabetcial letters in a string: "<<Alphabets<<endl;
   	cout<<"Total spaces in a string: "<<space<<endl;
   	cout<<endl;
	cout<<"                     --------------------"<<endl;
   
	}
	
	
	
	void String_Concat(string str)
	{
		string str2;
		cout<<"Firstly, Let's input another string, to concatinate it with previous one !"<<endl;
		cin.ignore();
		getline(cin,str2);
		string  concate;
		concate=str.append(str2);
		
		cout<<"Concatinated strings is : "<<concate<<endl;
		cout<<endl;
		cout<<"                     --------------------"<<endl;
		
	}

};



   	void upper_to_lower(String_converter obj)
   	{
		for(int i=0;obj.text[i]!='\0';i++)
		{
			if (obj.text[i] >= 'A' && obj.text[i] <= 'Z')  
				obj.text[i] = obj.text[i] + 32;        
		}
		cout<<"\n The string in lower case: "<< obj.text<<endl;
		cout<<endl;
		cout<<"                     --------------------"<<endl;
   	}  
   	
   	
   
   	void lower_to_upper(String_converter obj)
   	{
   		for(int i=0;obj.text[i]!='\0';i++)
		{
			if (obj.text[i] >= 'a' && obj.text[i] <= 'z')  
				obj.text[i] = obj.text[i] - 32;        
		}
		cout<<"\n The string in upper case: "<< obj.text<<endl;
		cout<<endl;
		cout<<"                     --------------------"<<endl;
    	}






class Validation: public String_converter
	{
		public:
		bool isValid(string str)
    		{
        		bool flag = true;
        		for (int i = 0; i <= str.length(); i++)
        		{
          			 if (str[i] >= 48 && str[i] <= 57)
                			flag = false;
           			else if (str[i] >= 0 && str[i]< 10 && str[i] >= 11 && str[i] <= 31)
              			flag = false;
           			else if (str[i] > 32 && str[i] <= 47)
               			flag = false;
           			else if (str[i] >= 58 && str[i] <= 64)
               			flag = false;
           			else if (str[i] > 91 && str[i] <= 96)
              			flag = false;
           			else if (str[i] > 123 && str[i] <= 126)
               			flag = false;
           			if (flag == false)
               			return false;
        		}
        	return true;
    	}
};





int main()
{
   	string str;
    	Validation s1;
    	char stop;
    	
	do
	{
    		cout << "Please enter any string of your own choice (A-Z && a-z):  ";
    		getline(cin, str);
    		
   		bool flag = s1.isValid(str);
   		while (flag == false)
    		{
        		cout << "\nYou entered invalid string.\n";
        		cout << "Please enter valid string contain only alphabets (A-Z && a-z): " ;
        		getline(cin, str);
        		flag = s1.isValid(str);
    		}
    		
    		s1.set_value(str);
    		cout<<endl;
    		cout << "The string you entered : " << s1.get_value() << endl;
    
   
     		cout<<"Which Operation you want to perform on string?"<<endl;
     		cout<<endl;
     		cout<<"1.Upper to Lower string Conversion."<<endl;
	 	cout<<"2.Lower to Upper string Conversion."<<endl;
	 	cout<<"3.Reversing the string."<<endl;
	 	cout<<"4.Counting alphabets and spaces in a string."<<endl;
	 	cout<<"5.Concatinate the string with newly entered string."<<endl;
	 	cout<<endl;
    		cout<<"Please choose any of the operation value :  ";
    		
    	 	int op;
    		cin>>op;
    		switch(op){
    		case 1:
    		upper_to_lower(str);
    		break;
    		case 2:
    		lower_to_upper(str);
    		break;
    		case 3:
    		s1.reverse(str);
     		break;  
    		case 4:
      	s1.count_strings( str);
      	break;
    		case 5:
      	s1.String_Concat( str);
      	break;  
      
       	default:
     		cout<<"you have entered wrong choice"<<endl;
 	}
      
    		cout << "Do you want to continue? (Y/N)" << endl;
    		cin >> stop;
    		cin.ignore();
    
}while(stop == 'y'|| stop =='Y');
	
		cout<<"Thank You for using our system!!!"<<endl;
		cout<<endl;
		cout<<"                  ***************************"<<endl;
	
    return 0;
}
