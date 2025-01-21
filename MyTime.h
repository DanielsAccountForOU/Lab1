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

MyTime operator + (const MyTime& t1, const MyTime& t2){
	MyTime tmp;
    tmp.hours = t1.hours + t2.hours;
	tmp.minutes = t1.minutes + t2.minutes;
	tmp.simplify();
	return tmp;
}

MyTime operator - (const MyTime& t1, const MyTime& t2){
	MyTime tmp;
	tmp.minutes = abs((t1.hours * 60 + t1.minutes) - (t2.hours * 60 + t2.minutes));
	tmp.simplify();
	return tmp;
}

MyTime operator / (const MyTime& t1, int num){
	MyTime tmp;
	tmp.minutes = t1.hours * 60 + t1.minutes;
	tmp.minutes /= num;
	tmp.simplify();
	return tmp;
}

MyTime operator * (const MyTime& t1, int num){
	MyTime tmp;
	tmp.minutes = t1.hours * 60 + t1.minutes;
	tmp.minutes *= num;
	tmp.simplify();
	return tmp;
}

bool operator == (const MyTime& t1, const MyTime& t2){
	return t1.hours == t2.hours && t1.minutes == t2.minutes;
}

bool operator < (const MyTime& t1, const MyTime& t2){
	return (t1.hours * 60 + t1.minutes) < (t2.hours * 60 + t2.minutes);
}

bool operator <= (const MyTime& t1, const MyTime& t2){
	return (t1.hours * 60 + t1.minutes) <= (t2.hours * 60 + t2.minutes);
}
