// Add documentation for each function

#include <iostream>
    
class MyTime
{   
	public:

		// CONVERT THESE CONSTRUCTORS INTO A SINGLE CONSTRUCTOR THAT USES 
		// DEFAULT ARGUMENTS
		//MyTime();
		//MyTime(int h, int m); 

		MyTime(int h = 0, int m = 0) : hours(h), minutes(m){} 

		    void input(istream& ins) {
        		char junk;
		        ins >> hours;
		        ins.get(junk);
		        ins >> minutes;
		        simplify();
		    }

		    void output(ostream& outs) const {
		        outs << setfill('0') << setw(2) << hours << ":" << setfill('0') << setw(2) << minutes;
		    }

		// Member functions
		void Reset(int h, int m);

		void input(std::istream& ins);            

		void output(std::ostream& outs);

		int get_hours() const{return hours;}

		int get_minutes() const{return minutes;}

		// Friend functions
		friend MyTime operator + (const MyTime& t1, const MyTime& t2);
	
		friend MyTime operator - (const MyTime& t1, const MyTime& t2);
	
		friend MyTime operator * (const MyTime& t1, int num);

		friend MyTime operator / (const MyTime& t1, int num);

		friend std::istream& operator >>(input(std::istream& ins), MyTime& t);
		
		friend std::ostream& operator <<(output(std::ostream& outs), const MyTime& t);

		friend bool operator == (const MyTime& t1, const MyTime& t2);

		friend bool operator < (const MyTime& t1, const MyTime& t2);

		friend bool operator <= (const MyTime& t1, const MyTime& t2);
   
  	private:
		void simplify();
		int hours;        // hours can be > 24
		int minutes;      // 0 <= minutes <= 59
 };

void MyTime::input(istream& ins){
	/* Move the implementation code from the >> operator show below here.
	   Remember that since this function will be a member now, there will not be a t1.

	   The >> operator should now call this function.
	   Remove the friend keyword from the operator in the .h file and move the
	   function prototype to after the class declaration.
	*/
	char junk;
	ins >> hours;
  	ins.get(junk);
	ins >> minutes;
	simplify();
}

void MyTime::output(ostream& outs){
	/* Repeat what you did for input except using the code for the << operator */
	outs << setfill('0') << setw(2) << hours << ':' << setfill('0') << setw(2) << minutes;
}
