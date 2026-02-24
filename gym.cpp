#include <iostream>
#include <string>
#include<conio.h>
#include<fstream>
using namespace std;
class person
{
protected:
	string name;
	int gender;
	int age;

public:
	void get_person_info()
	{
		//STRINGS************
		cout << "name:";
		cin.ignore();//to ignore the new line buffer
		getline(cin, name);
		cout << "age:";
		cin >> age;
		cout << "gender:\n1.male\n2.female" << endl;
		cout << "enter your gender:";
		cin >> gender;
	}

	void display_peron_info()
	{
		cout << "name: " << name << endl;
		cout << "age: " << age << endl;
		cout << "1.male\n2.female" << endl;
		cout << "gender: " << gender << endl;
	}

	//friend function***********
	friend int return_gender(person p);
	//to return gender which will be used furthe (while accessing OPTION 2) that is gym member login....
	//and will accordingly provide data for dietplan and workout plan....
};

int return_gender(person p)//friend function
{
	return p.gender;
}

class membership :public person
{
protected:
	string membership_type;
	double fee;
	string timeslot;

public:
	//pure virtual function************
	//(membership)---->(gymmember)--->--->DIETPLAN AND WORKOUTPLAN
	virtual void displayplan() = 0;

	void get_membership_info()
	{
		int mem_tp_choice;
		cout << endl;
		cout << "ENTER MEMBERSHIP DETAILS" << endl;
		cout << "1.basic-1000" << endl;
		cout << ":one month regular strength\n" << endl;
		cout << "2.premium-2000" << endl;
		cout << ":two months + free one month regular strength" << endl;
		cout << ":access to cardio machines\n" << endl;
		cout << "3.vip-3000" << endl;
		cout << ":three months + free one month regular strength" << endl;
		cout << ":access to cardio machines" << endl;
		cout << ":persnol gym trainer\n" << endl;
		cout << "enter membership type:";
		cin >> mem_tp_choice;

		if (mem_tp_choice == 1)
		{
			membership_type = "Basic";
			fee = 1000;
		}
		else if (mem_tp_choice == 2)
		{
			membership_type = "Premium";
			fee = 2000;
		}
		else if (mem_tp_choice == 3)
		{
			membership_type = "VIP";
			fee = 3000;
		}
		else
		{
			cout << "Invalid input!" << endl;
			cout << "setting your membership to basic!" << endl;
			membership_type = "Basic";
			fee = 1000;
		}
		cout << "membership type:" << membership_type << endl;
		cout << "fee: " << fee << endl;
	}

	void display_membership_info()
	{
		cout << "membership type: " << membership_type << endl;
		cout << "fee: " << fee << endl;
	}

	void gym_services_info()
	{
		cout << "\nOUR SERVICES:" << endl;
		cout << ":weight gain / weight loss" << endl;
		cout << ":cardio" << endl;
		cout << ":body fitness" << endl;
		cout << ":personal training" << endl;
		cout << ":personalized diet plan\n" << endl;
	}

	void gym_timing_info()
	{
		cout << "gym timing:" << endl;
		cout << "MORNING: 6.00am-10.30am" << endl;
		cout << "EVENING: 4.00pm-10.00pm" << endl;
		cout << "sunday closed!\n" << endl;
	}
};

//templates************
//(inside the int main....while creating objects of the class...two different datamembers....int and string are passed)
template <typename T1, typename T2>
class trainer :public person
{
protected:
	T1 trainer_id;
	T2 speacility;

public:

	void get_trainer_info()
	{
		static int t_id = 100;
		get_person_info();
		trainer_id = t_id;
		t_id++;
		cout << "speacility: ";
		cin.ignore();
		getline(cin, speacility);
		cout << "trainer ID assigned to you:" << trainer_id << endl;
	}

	int get_trainerid()const
	{
		return trainer_id;
	}

	void display_trainer_info()
	{
		cout << "trainer id: " << trainer_id << endl;
		display_peron_info();
		cout << "spacility: " << speacility << endl;
	}
};

class suppliments_and_accessories
{
protected:
	string sup_name[5];
	string acc_name[5];
	double sup_price[5];
	double acc_price[5];
	double total_bill = 0;

public:
	//constructor************
	//will be invoked automatically while creating objects of this class...
	suppliments_and_accessories()
	{
		sup_name[0] = "POTEIN POWDER";
		sup_name[1] = "CRETINE";
		sup_name[2] = "MULTIVITAMIN";
		sup_name[3] = "BCAA";
		sup_name[4] = "FISH OIL";

		sup_price[0] = 2000;
		sup_price[1] = 600;
		sup_price[2] = 300;
		sup_price[3] = 800;
		sup_price[4] = 400;

		acc_name[0] = "GYM_TOWEL";
		acc_name[1] = "YOGAMAT";
		acc_name[2] = "RESISTANCE BAND";
		acc_name[3] = "WRIST SUPPORTER";
		acc_name[4] = "SHAKER BOTTLE";

		acc_price[0] = 200;
		acc_price[1] = 600;
		acc_price[2] = 400;
		acc_price[3] = 300;
		acc_price[4] = 800;
	}

	//destructor************
	~suppliments_and_accessories() { }

	//inline function************
	inline void display_suppliments_info()
	{
		for (int i = 0; i < 5; i++)
		{
			cout << i + 1 << " " << sup_name[i] << " price: " << sup_price[i] << endl;
		}
	}
	//inline function************
	inline void display_accessories_info()
	{
		for (int i = 0; i < 5; i++)
		{
			cout << i + 1 << " " << acc_name[i] << " price: " << acc_price[i] << endl;
		}
	}

	void buy_sup()
	{
		int choice, quantity;
		int option;
		do
		{
			display_suppliments_info();
			cout << "Enter choice: ";
			cin >> choice;
			if (choice < 1 || choice > 5)
			{
				cout << "Invalid choice!" << endl;
				continue;
			}
			cout << "Enter quantity: ";
			cin >> quantity;

			total_bill = total_bill + sup_price[choice - 1] * quantity;
			cout << "Want to buy more supplements?\n1.yes\n2.no" << endl;
			cout << "enter your choice:";
			cin >> option;
		} while (option == 1);
	}

	void buy_acc()
	{
		int choice, quantity;
		int optionnn;
		do
		{
			display_accessories_info();
			cout << "Enter choice: ";
			cin >> choice;
			if (choice < 1 || choice > 5)
			{
				cout << "Invalid choice!" << endl;
				continue;
			}
			cout << "Enter quantity: ";
			cin >> quantity;

			total_bill = total_bill + acc_price[choice - 1] * quantity;
			cout << "Want to buy more accessories?\n1.yes\n2.no" << endl;
			cout << "enter your choice:";
			cin >> optionnn;
		} while (optionnn == 1);
	}

	//operator overloading************
	//(first obj will be used for storing bill info for suppliments)...(second object will be use for storing bill for accessories)...
	//OBJECT_3=OBJECT_1+OBJECT_2...
	suppliments_and_accessories operator+(suppliments_and_accessories SECOND);
	void display_total_bill()
	{
		cout << "\nTOTAL BILL: " << total_bill << endl;
	}
};

suppliments_and_accessories suppliments_and_accessories::operator+(suppliments_and_accessories SECOND)
{
	suppliments_and_accessories temp;
	temp.total_bill = total_bill + SECOND.total_bill;
	return temp;
}

class gymmember : public membership, public suppliments_and_accessories
{
protected:
	int memberid;
public:

	//files************
	//(consepts of files to write data inside a file)...
	void writecustomerdata()
	{
		ofstream fout("MemberDetails.txt", ios::app);
		if (fout.is_open())
		{
			fout << "Member ID:" << memberid << endl;
			fout << "Name:" << name << endl;
			fout << "Age:" << age << endl;
			fout << "Membership Type:" << membership_type << endl;
			fout << "____________________" << endl;
			fout.close();
			cout << "Member data saved succesfully" << endl;
		}
		else
		{
			cout << "Error:Could not open file!!" << endl;
		}
	}

	//(consepts of files to display data inside a file)...
	void displaycustomerdata()
	{
		ifstream fin("MemberDetails.txt");
		if (fin.is_open())
		{
			string line;
			cout << "Member Details:\n";
			cout << "____________________" << endl;
			while (getline(fin, line))
				cout << line << endl;
			fin.close();
		}
		else
		{
			cout << "Error:Could not open file!!\n";
		}
	}

	void displayplan()//(part of virtual function)
	{

	}

	void get_members_info()
	{
		static int m_id = 1000;
		memberid = m_id;
		m_id++;
		gym_services_info();
		gym_timing_info();
		cout << "ENTER DETAILS:" << endl;
		get_person_info();
		get_membership_info();
		cout << "member id assigned to you:" << memberid << endl;
	}

	int get_memberid()const
	{
		return memberid;
	}

	void display_member_info()
	{
		cout << "member id: " << memberid << endl;
		display_peron_info();
		display_membership_info();
	}
};

class DietPlan :public gymmember
{
protected:
	int currentWeight;
	int targetWeight;
	int goal;

public:
	void input_dietplan_Details()
	{
		cout << "Enter your current weight:";
		cin >> currentWeight;
		cout << "Do you want to lose or gain weight?\n1.lose\n2.gain: ";
		cin >> goal;
		//exception handling************
		//(will throw error for invalid input)...
		try
		{
			if (goal != 1 && goal != 2)
			{
				throw(2);
			}
			else if (goal == 1)
			{
				cout << "goal: weight loss" << endl;
			}
			else if (goal == 2)
			{
				cout << "goal: weight gain" << endl;
			}
		}
		catch (int j)
		{
			cout << "invalid input for goal!" << endl;
		}
		cout << "Enter your target weight: ";
		cin >> targetWeight;
		cout << endl;
	}

	void displayplan(int var)
	{
		input_dietplan_Details();
		if (goal == 1)
		{
			if (currentWeight > targetWeight)
			{
				if (var == 1)
				{
					cout << "male loss" << endl;
					cout << "1. Calorie intake:\nreduce calorie intake by 800cal\nmaximun calorie intake:1800-2000 cal/day\n" << endl;
					cout << "2. Diet:\nBREAKFAST:\n(veg)-(nonveg) 1 bowl of fruits, green tea\n";
					cout << "LUNCH:\n(veg) 1 cup dal , rice , 50 gm paneer , 1 plate sala\n(nonveg) chicken rice , 1 plate salad\n";
					cout << "DINNER:\n(veg) 2 roti , 1 bowl paneer bhurji , 1 cup lo-fat curd\n(nonveg) 2 roti , 1 bowl egg bhurji , 1 cup lowfat curd\n" << endl;
					cout << "3. Exercise:\nWeight lifting 4-5 times a week\n";
					cout << "stay hydrated! (3-4 liter) of water/day\n" << endl;
				}
				else if (var == 2)
				{
					cout << "female loss" << endl;
					cout << "1. Calorie intake:\nreduce calorie intake by 600cal\nmaximun calorie intake:1500-1600 cal/day\n" << endl;
					cout << "2. Diet:\nBREAKFAST:\n(veg)-(nonveg) 1 bowl of fruits, green tea\n";
					cout << "LUNCH:\n(veg) 1 cup dal , rice , 50 gm paneer , 1 plate sala\n(nonveg) chicken rice , 1 plate salad\n";
					cout << "DINNER:\n(veg) 2 roti , 1 bowl paneer bhurji , 1 cup lo-fat curd\n(nonveg) 2 roti , 1 bowl egg bhurji , 1 cup lowfat curd\n" << endl;
					cout << "3. Exercise:\nWeight lifting 4-5 times a week\n";
					cout << "stay hydrated! (3-4 liter) of water/day\n" << endl;
				}
			}
			else
			{
				cout << "\nYour target weight should be less than your current weight\n";
			}
		}
		else if (goal == 2)
		{
			if (currentWeight < targetWeight)
			{
				if (var == 1)
				{
					cout << "male gain" << endl;
					cout << "1. Calorie intake:\nincrease calorie intake by 1000cal\nminimum calorie intake:2800-3000 cal/day\n" << endl;
					cout << "2. Diet:\nBREAKFAST:\n(veg) 1 cup oats , 1 banana , 15-20 almonds\n(nonveg) 1 cup oats , 2 boiled eggs , 10-15 almonds\n";
					cout << "LUNCH:\n(veg) 1/2 cup brown rice , 1 bowl rajma , 1 plate salad\n(nonveg) chicken rice , 1 plate salad\n";
					cout << "DINNER:\n(veg) 2 roti , 1 bowl paneer bhurji , 1 cup yogurt\n(nonveg) 2 roti , 1 bowl egg bhurji , 1 cup yogurt\n" << endl;
					cout << "3. Exercise:\nWeight lifting 4-5 times a week\n";
					cout << "stay hydrated! (3-4 liter) of water/day\n" << endl;
				}
				else if (var == 2)
				{
					cout << "female gain" << endl;
					cout << "1. Calorie intake:\nincrease calorie intake by 600cal\nminimum calorie intake:1800-2000 cal/day\n" << endl;
					cout << "2. Diet:\nBREAKFAST:\n(veg) 1 cup oats , bowl of fruits\n(nonveg) 1 cup oats , 2 boiled eggs\n";
					cout << "LUNCH:\n(veg) 1/2 cup brown rice , 1 bowl rajma\n(nonveg) chicken rice , 1 plate salad\n";
					cout << "DINNER:\n(veg) 2 roti , 1 bowl paneer bhurji , 1 cup yogurt\n(nonveg) 2 roti , 1 bowl egg bhurji , 1 cup yogurt\n" << endl;
					cout << "3. Exercise:\nWeight lifting 4-5 times a week\n";
					cout << "stay hydrated! (2-2.5 liter) of water/day\n" << endl;
				}
			}
			else
			{
				cout << "\nYour target weight should be greater than your current weight\n";
			}
		}
		else
		{
			cout << "invalid input while entering data!" << endl;
		}
	}
};

class WorkoutPlan :public gymmember
{
protected:
	int workoutType;

public:
	void input_workoutplan_Details()
	{
		cout << "\nEnter workout plan type:\n";
		cout << "1.Weight Training\n";
		cout << "2.Cardio\n";
		cout << "Enter your choice:";
		cin >> workoutType;

		//exception handling************
		//(will throw error for invalid input)...
		try
		{
			if (workoutType != 1 && workoutType != 2)
			{
				throw (1);
			}
			else if (workoutType == 1)
			{
				cout << "selected weight training plan" << endl;
			}
			else if (workoutType == 2)
			{
				cout << "selected cardio training plan" << endl;
			}
		}
		catch (int i)
		{
			cout << "invalid input for workout plan!" << endl;
		}
		cout << endl;
	}

	void displayplan(int var)
	{
		input_workoutplan_Details();
		if (workoutType == 1)
		{
			if (var == 1)
			{
				cout << "weight training male" << endl;
				cout << "Monday: Chest and Triceps\n1.cable chest flies\n2.inclined dumbel press\n3.declined barbell press\n4.tricep pushdown\n5.overhead tricep extension\n" << endl;
				cout << "Tuesday: Back and Biceps\n1.lats pulldown\n2.back cable row\n3.pull ups\n4.dumbell bisep curls\n5.preacher curls\n" << endl;
				cout << "Wednesday: Legs\n1.squats\n2.legs extension\n3.leg press\n4.calf raises\n" << endl;
				cout << "Thursday: Shoulders\n1.shoulder press\n2.lateral raise\n3.shrugs\n4.rear delt raises\n" << endl;
				cout << "Friday: Core\n1.crunches\n2.v ups\n3.planks\n4.leg raises\n" << endl;
				cout << "Saturday: strength lifting\n1.deadlift\n2.squats\n3.bench press\n" << endl;
				cout << "Sunday: Rest Day\n" << endl;
			}
			else if (var == 2)
			{
				cout << "weight training female" << endl;
				cout << "Monday: Chest and Triceps\n1.cable chest flies\n2.inclined dumbel press\n3.declined barbell press\n4.tricep pushdown\n5.overhead tricep extension\n" << endl;
				cout << "Tuesday: Back and Biceps\n1.lats pulldown\n2.back cable row\n3.pull ups\n4.dumbell bisep curls\n5.preacher curls\n" << endl;
				cout << "Wednesday: Legs\n1.squats\n2.legs extension\n3.leg press\n4.calf raises\n" << endl;
				cout << "Thursday: Shoulders\n1.shoulder press\n2.lateral raise\n3.shrugs\n4.rear delt raises\n" << endl;
				cout << "Friday: Core\n1.crunches\n2.v ups\n3.planks\n4.leg raises\n" << endl;
				cout << "Saturday: strength lifting\n1.deadlift\n2.squats\n3.bench press\n" << endl;
				cout << "Sunday: Rest Day\n" << endl;
			}
		}
		else if (workoutType == 2)
		{
			if (var == 1)
			{
				cout << "cardio male" << endl;
				cout << "Monday-thursday:\n1.walking:30 min\n2.running 30 min\n" << endl;
				cout << "Tuesday-friday:\n1.Cycling:1 hour\n2.core exercise 30 min\n" << endl;
				cout << "Wednesday-saturday:\n1.sprint:100 meter-5 times\n2.rope jump 10 min\n" << endl;
				cout << "Sunday: Rest Day\n" << endl;
			}
			else if (var == 2)
			{
				cout << "cardio female" << endl;
				cout << "Monday-thursday:\n1.walking:30 min\n2.running 15 min\n" << endl;
				cout << "Tuesday-friday:\n1.Cycling:45 min\n2.core exercise 10 min\n" << endl;
				cout << "Wednesday-saturday:\n1.sprint:100 meter-2 times\n2.rope jump 20 min\n" << endl;
				cout << "Sunday: Rest Day\n" << endl;
			}
		}
		else
		{
			cout << "Invalid input while entering data!" << endl;
		}
	}
};

//default arguments************()
int calculate_weight_difference(int cw = 0, int lw = 0);

//function overloading(for int)
int calculate_weight_difference(int cw, int lw)
{
	return cw - lw;
}

//default arguments************()
float calculate_weight_difference(float cw = 0, float lw = 0);

//function overloading()for float
float calculate_weight_difference(float cw, float lw)
{
	return cw - lw;
}

void display_result(float wd)
{
	if (wd < 0)
	{
		cout << "you lost " << -wd << " kg" << endl;
	}
	else if (wd > 0)
	{
		cout << "you gained " << wd << " kg" << endl;
	}
	else
	{
		cout << "same weight!" << endl;
	}
}

void main()
{
	cout << "GYM MANAGEMENT SYSTEM" << endl;
	const int max_members = 100;
	const int max_trainers = 20;
	gymmember m[max_members];
	//templates(passing two different data types)
	trainer<int, string> t[max_trainers];
	int members_count = 0;
	int trainers_count = 0;
	int choicee;
	do
	{
		int choice = 0;
		cout << endl;
		cout << "1. Admin\n";
		cout << "2. Gym Member\n";
		cout << "3. Exit\n";
		cout << "Enter your choice: ";
		cin >> choicee;

		if (choicee == 1)
		{
			cout << endl;
			cout << "WELCOME ADMIN\n";
			while (choice != 11)
			{
				cout << endl;
				cout << "1. register Gym Member" << endl;
				cout << "2. Add Trainer" << endl;
				cout << "3. Display  Perticular Gym Member Info" << endl;
				cout << "4. Display  Perticular Trainer Info" << endl;
				cout << "5. Display all registered member" << endl;
				cout << "6. Display all added Trainers" << endl;
				cout << "7. Delete Gym Member" << endl;
				cout << "8. Delete Trainer" << endl;
				cout << "9. Renewing Gym Membership " << endl;
				cout << "10. Display File Content" << endl;//(will display deleted members tooooo)...
				cout << "11. Exit" << endl;
				cout << "Enter Your Choice: ";
				cin >> choice;

				switch (choice)
				{
				case 1:
					if (members_count >= max_members)
					{
						cout << "members full!" << endl;
					}
					else
					{
						m[members_count].get_members_info();
						//files(data of perticular member will be written inside a file)...
						m[members_count].writecustomerdata();
						members_count++;
					}
					break;
				case 2:
					if (trainers_count >= max_trainers)
					{
						cout << "trainers full!" << endl;
					}
					else
					{
						cout << "enter trainer deails: " << endl;
						t[trainers_count].get_trainer_info();
						trainers_count++;
					}
					break;

				case 3:
					if (members_count == 0)
					{
						cout << "no members to display!" << endl;
					}
					else
					{
						int m_id;
						cout << "enter member id:";
						cin >> m_id;
						int m_found;
						m_found = 0;
						for (int i = 0; i < members_count; i++)
						{
							if (m[i].get_memberid() == m_id)
							{
								m[i].display_member_info();
								m_found = 1;
								break;
							}
						}
						if (m_found == 0)
						{
							cout << "member with such id not found!" << endl;
						}
					}
					break;
				case 4:
					if (trainers_count == 0)
					{
						cout << "no trainers to display!" << endl;
					}
					else
					{
						int t_id;
						cout << "enter trainer id:";
						cin >> t_id;
						int t_found;
						t_found = 0;
						for (int i = 0; i < trainers_count; i++)
						{
							if (t[i].get_trainerid() == t_id)
							{
								t[i].display_trainer_info();
								t_found = 1;
								break;
							}
						}
						if (t_found == 0)
						{
							cout << "trainer with such id not found!" << endl;
						}
					}
					break;
				case 5:
					if (members_count == 0)
					{
						cout << "no members to display!" << endl;
					}
					else
					{
						cout << "information: " << endl;
						for (int i = 0; i < members_count; i++)
						{
							m[i].display_member_info();
							cout << "___________________________" << endl;
						}
					}
					break;
				case 6:
					if (trainers_count == 0)
					{
						cout << "no trainers to display!" << endl;
					}
					else
					{
						cout << "information: " << endl;
						for (int i = 0; i < trainers_count; i++)
						{
							t[i].display_trainer_info();
							cout << "___________________________" << endl;
						}
					}
					break;
				case 7:
					if (members_count == 0)
					{
						cout << "no members to display!" << endl;
					}
					else
					{
						int d_m_id;
						cout << "enter member id to delete:";
						cin >> d_m_id;
						int d_m_found;
						d_m_found = 0;
						for (int i = 0; i < members_count; i++)
						{
							if (m[i].get_memberid() == d_m_id)
							{
								for (int j = i; j < members_count - 1; j++)
								{
									m[j] = m[j + 1];
								}
								members_count--;
								d_m_found = 1;
								cout << "deleted!" << endl;
								break;
							}
						}
						if (d_m_found == 0)
						{
							cout << "member id not found!" << endl;
						}
					}
					break;
				case 8:
					if (trainers_count == 0)
					{
						cout << "no trainers to display!" << endl;
					}
					else
					{
						int d_t_id;
						cout << "enter trainer id to delete:";
						cin >> d_t_id;
						int d_t_found;
						d_t_found = 0;
						for (int i = 0; i < trainers_count; i++)
						{
							if (t[i].get_trainerid() == d_t_id)
							{
								for (int j = i; j < trainers_count - 1; j++)
								{
									t[j] = t[j + 1];
								}
								trainers_count--;
								d_t_found = 1;
								cout << "deleted!" << endl;
							}
						}
						if (d_t_found == 0)
						{
							cout << "trainer id not found!" << endl;
						}
					}
					break;
				case 9:
				{
					if (members_count == 0)
					{
						cout << "no members to update!" << endl;
					}
					else
					{
						int update_id;
						cout << "enter id to update gym membership: ";
						cin >> update_id;
						int update_found;
						update_found = 0;
						for (int i = 0; i < members_count; ++i)
						{
							if (m[i].get_memberid() == update_id)
							{
								cout << "updating fmembership for: " << update_id << endl;
								m[i].display_peron_info();
								m[i].get_membership_info();
								update_found = 1;
								cout << "information updated!" << endl;
								break;
							}
						}
						if (update_found == 0)
						{
							cout << "member id not found! " << endl;
						}
					}
					break;
				}
				case 10:
				{
					m[0].displaycustomerdata();//(display file content)...(will display the deleted members too)....
					break;
				}
				case 11:
				{
					cout << "EXITING...." << endl;
					break;
				}
				default:
					cout << "invalid choice!" << endl;
				}
			}
		}
		else if (choicee == 2)
		{
			int var;
			int select_m_id;
			cout << "enter membe id to login:";
			cin >> select_m_id;
			int mm_found;
			mm_found = 0;
			for (int i = 0; i < members_count; i++)
			{
				if (m[i].get_memberid() == select_m_id)
				{
					cout << endl;
					cout << "member info:" << endl;
					m[i].display_peron_info();
					mm_found = 1;
					if (return_gender(m[i]) == 1)//friend function
					{
						var = 1;
					}
					else
					{
						var = 2;
					}
				}
			}
			if (mm_found == 0)
			{
				cout << "member with such id not found!" << endl;
			}
			else
			{
				cout << "welcome!\n";
				while (choice != 5)
				{
					cout << endl;
					cout << "1. Buying Gym Suppliments And Accesories" << endl;
					cout << "2. Dietplan " << endl;
					cout << "3. Workoutplan" << endl;
					cout << "4. calculate weight difference" << endl;
					cout << "5. Exit" << endl;
					cout << "Enter Your Choice: ";
					cin >> choice;

					switch (choice)
					{

					case 1:
					{
						{
							//operator overloading()...
							suppliments_and_accessories c1, c2, c3;
							cout << "AVAILABLE SUPPLIMENTS" << endl;
							c1.buy_sup();
							int buyAccessories;
							cout << "\nDo you want to buy gym accessories?\n1.yes\n2.no " << endl;
							cout << "your choice: ";
							cin >> buyAccessories;

							if (buyAccessories == 1)
							{
								cout << "\nAVAILABLE ACCESSORIES" << endl;
								c2.buy_acc();
							}
							c3 = c1 + c2;
							c3.display_total_bill();
						}
						break;
					}
					//(PVF)...
					case 2:
					{
						if (var == 1)
						{
							DietPlan dp;
							int v = 1;
							dp.displayplan(v);
							break;
						}
						else
						{
							DietPlan dp;
							int v = 2;
							dp.displayplan(v);
							break;
						}
					}
					//(PVF)...
					case 3:
					{
						if (var == 1)
						{
							WorkoutPlan wp;
							int v = 1;
							wp.displayplan(v);
							break;
						}
						else
						{
							WorkoutPlan wp;
							int v = 2;
							wp.displayplan(v);
							break;
						}
					}
					case 4:
					{
						int ipt;
						cout << "1.integer weight values\n2.floating weight values" << endl;
						cin >> ipt;

						if (ipt == 1)
						{
							int currentweight, lastmonthweight;
							cout << "enter current month weight:";
							cin >> currentweight;
							cout << "enter last month weight:";
							cin >> lastmonthweight;
							int difference;
							difference = calculate_weight_difference(currentweight, lastmonthweight);
							display_result(difference);
						}
						else if (ipt == 2)
						{
							float currentweight, lastmonthweight;
							cout << "enter current month weight:";
							cin >> currentweight;
							cout << "enter last month weight:";
							cin >> lastmonthweight;
							float difference;
							difference = calculate_weight_difference(currentweight, lastmonthweight);
							display_result(difference);
						}
						else
						{
							cout << "invalid input!" << endl;
						}
						break;
					}
					case 5:
					{
						cout << "EXITING...." << endl;
						break;
					}
					default:
						cout << "invalid choice!" << endl;
					}
				}
			}
		}
		else if (choicee == 3)
		{
			cout << "logging off..... " << endl;
		}
		else
		{
			cout << "invalid input!" << endl;
		}
	} while (choicee != 3);
	_getch();
}