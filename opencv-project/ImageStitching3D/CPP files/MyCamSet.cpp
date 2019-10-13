#include "..\Header\Header.h"


using namespace std;

MyCamSet MyCamSet::sett()
{
	MyCamSet cameras;

	

	return cameras;
}

int x11[2] = {70,-70 };
///int x12[2] = {-30,-110 };
//int x11[2] = { 30,110 };
//int x12[2] = { -30,-110 };


int x21[3] = { 130,-10,10 };
///int x22[2] = { -50,30 };
//int x21[2] = { 90,170 };
//int x22[2] = { -50,30 };



int x31[3] = { 50,-170,130 };
///int x32[2] = { 10,90 };
//int x31[2] = { 150,-130 };
//int x32[2] = { 10,90 };


int x41[2] = { 110,-110};
///int x42[2] = { 70,150 };
//int x41[2] = { -150,-70 };
//int x42[2] = { 70,150 };


int x51[3] = { 170,-50,-150};
///int x52[2] = { 130,-150 };
//int x51[2] = { -90,-10 };
//int x52[2] = { 130,-150 };


int x61[3] = { 10,-130,-10 };
///int x62[2] = { -170,-90 };
//int x61[2] = { -30,50 };
//int x62[2] = { -170,-90 };





//int yy1[2] = {-10,70};
//int yy2[2] = {50,130};
//int yy3[2] = {110,-170};
//int yy4[2] = {170,-110};
//int yy5[2] = {-50,-130};
//int yy6[2] = {10,-70};


///OHNISKA////////////////////////////////////////////////////////////////////////////
//*******OHNISKO 1 ******////


//int cam[35] = {};

 bool *polesmernikov[6] = {false,false ,false ,false ,false ,false };



//int cam4[6] = { 0,0,0,0,0,0 };

bool* choseCam(int x, int y);
bool* choseCam2(int x, int y);
bool* choseCam3(int x, int y);
bool* choseCam4(int x, int y);
bool* choseCam5(int x, int y);
bool* choseCam6(int x, int y);

/*
bool inRange1(int low, int high, int x,int y)
{
	return ( ((x - high)*(x - low)) || ((y - high)*(y - low))  <= 0);
}
*/


//int *gh;
//bool *chuj;
//int *chujovina[6];


bool  inRange2(int low, int high, int x, int y,int h,int pom)
{


	if ((((x - high)*(x - low)) <= 0) == true ){
		if (h ==1){
			//choseCam( x, y);
			//gh=(choseCam(x, y));
			polesmernikov[0] = (choseCam(x, y));
			//chuj = (choseCam(x, y));
			//kokotina[0] = chuj;
			//std::cout << "0 " << &kokotina[0] << '\n';
			
			//std::cout << "k " << *(chujovina[0] + 1) << '\n';
			return ((((x - high)*(x - low)) <= 0));
		}

		if (h == 2) {
			//choseCam2(x, y);
			//chuj = (choseCam2(x, y));
			polesmernikov[1] = (choseCam2(x, y));
			//std::cout << "k " << *(kokotina[0] + 3) << '\n';
			return ((((x - high)*(x - low)) <= 0));
		}

		if (h == 3) {
			//choseCam3(x, y);
			polesmernikov[2] = (choseCam3(x, y));
			return ((((x - high)*(x - low)) <= 0));
		}

		if (h == 4) {
			//choseCam4(x, y);
			polesmernikov[3] = (choseCam4(x, y));
			return ((((x - high)*(x - low)) <= 0));
		}

		if (h == 5) {
			//choseCam5(x, y);
			polesmernikov[4] = (choseCam5(x, y));
			return ((((x - high)*(x - low)) <= 0));
		}

		if (h == 6) {
			//choseCam6(x, y);
			polesmernikov[5] = (choseCam6(x, y));
			return ((((x - high)*(x - low)) <= 0));
		}


	}
	else
	{
		return ((((x - high)*(x - low)) <= 0));
	}

	

}


bool* choseCam(int x, int y)
{
	static	bool cam1[6] = { false,false,false,false,false,false };
	

	if (x > 0) {
		if (y == 1) {
			cam1[0]  = 1;
			cam1[5]  = 1;
		}
		if (y == 2) {
			cam1[0] = 1;
			cam1[1] = 1;
		}
		if (y == 3) {
			cam1[4] = 1;
			cam1[5] = 1;
		}

	}
	else {

		if (y == 1) {
			cam1[2] = 1;
			cam1[3] = 1;
		}
		if (y == 2) {
			cam1[1] = 1;
			cam1[2] = 1;
		}
		if (y == 3) {
			cam1[3] = 1;
			cam1[4]  = 1;
		}

	}

	std::cout << "cam11 " << cam1[0] << '\n';
	std::cout << "cam12 " << cam1[1] << '\n';
	std::cout << "cam13 " << cam1[2] << '\n';
	std::cout << "cam14 " << cam1[3] << '\n';
	std::cout << "cam15 " << cam1[4] << '\n';
	std::cout << "cam16 " << cam1[5] << '\n';

	std::cout << "adresa1 " << &cam1 << '\n';
	std::cout << "adresa10 " << &cam1[0] << '\n';
	return cam1;
}


bool*  choseCam2(int x, int y)
{
	static	bool cam2[6] = { false,false,false,false,false,false };


	if (x > 30) {
		if (y == 1) {
			cam2[0] = true;
			cam2[5] = true;
		}
		if (y == 2) {
			cam2[0] = true;
			cam2[1] = true;
		}
		if (y == 3) {
			cam2[4] = true;
			cam2[5] = true;
		}

	}
	else {

		if (y == 1) {
			cam2[2] = true;
			cam2[3] = true;
		}
		if (y == 2) {
			cam2[1] = true;
			cam2[2] = true;
		}
		if (y == 3) {
			cam2[3] = true;
			cam2[4] = true;
		}

	}

	std::cout << "cam21 " << cam2[0] << '\n';
	std::cout << "cam22 " << cam2[1] << '\n';
	std::cout << "cam23 " << cam2[2] << '\n';
	std::cout << "cam24 " << cam2[3] << '\n';
	std::cout << "cam25 " << cam2[4] << '\n';
	std::cout << "cam26 " << cam2[5] << '\n';



	return (cam2);
}

bool*  choseCam3(int x, int y)
{

	static bool cam3[6] = { false,false,false,false,false,false };

	if (x > 0 && x < 130 ) {
		if (y == 1) {
			cam3[2] = 1;
			cam3[3] = 1;
		}
		if (y == 2) {
			cam3[1] = 1;
			cam3[2] = 1;
		}
		if (y == 3) {
			cam3[3] = 1;
			cam3[4] = 1;
		}

	}
	else {

		if (y == 1) {
			cam3[5] = 1;
			cam3[0] = 1;
		}
		if (y == 2) {
			cam3[0] = 1;
			cam3[1] = 1;
		}
		if (y == 3) {
			cam3[4] = 1;
			cam3[5] = 1;
		}

	}




	std::cout << "cam31 " << cam3[0] << '\n';
	std::cout << "cam32 " << cam3[1] << '\n';
	std::cout << "cam33 " << cam3[2] << '\n';
	std::cout << "cam34 " << cam3[3] << '\n';
	std::cout << "cam35 " << cam3[4] << '\n';
	std::cout << "cam36 " << cam3[5] << '\n';

	return (cam3);
}


bool*  choseCam4(int x, int y)
{
	
	static bool cam4[6] = { false,false,false,false,false,false };

	if (x > 0) {
		if (y == 1) {
			cam4[2] = 1;
			cam4[3] = 1;
		}
		if (y == 2) {
			 cam4[1] = 1;
			 cam4[2] = 1;
		}
		if (y == 3) {
			 cam4[3] = 1;
			 cam4[4] = 1;
		}

	}
	else {

		if (y == 1) {
			 cam4[5] = 1;
			 cam4[0] = 1;
		}
		if (y == 2) {
			 cam4[0] = 1;
			 cam4[1] = 1;
		}
		if (y == 3) {
			 cam4[4] = 1;
			 cam4[5] = 1;
		}

	}

	


	std::cout << "cam41 " << cam4[0] << '\n';
	std::cout << "cam42 " << cam4[1] << '\n';
	std::cout << "cam43 " << cam4[2] << '\n';
	std::cout << "cam44 " << cam4[3] << '\n';
	std::cout << "cam45 " << cam4[4] << '\n';
	std::cout << "cam46 " << cam4[5] << '\n';

	return ( cam4);
}

bool* choseCam5(int x, int y)
{

	static bool cam5[6] = { false,false,false,false,false,false };

	if (x > 0 || x == -150  ) {
		if (y == 1) {
			cam5[2] = 1;
			cam5[3] = 1;
		}
		if (y == 2) {
			cam5[1] = 1;
			cam5[2] = 1;
		}
		if (y == 3) {
			cam5[3] = 1;
			cam5[4] = 1;
		}

	}
	else {

		if (y == 1) {
			cam5[5] = 1;
			cam5[0] = 1;
		}
		if (y == 2) {
			cam5[0] = 1;
			cam5[1] = 1;
		}
		if (y == 3) {
			cam5[4] = 1;
			cam5[5] = 1;
		}

	}




	std::cout << "cam51 " << cam5[0] << '\n';
	std::cout << "cam52 " << cam5[1] << '\n';
	std::cout << "cam53 " << cam5[2] << '\n';
	std::cout << "cam54 " << cam5[3] << '\n';
	std::cout << "cam55 " << cam5[4] << '\n';
	std::cout << "cam56 " << cam5[5] << '\n';

	return (cam5);
}

bool*  choseCam6(int x, int y)
{
	static	bool cam6[6] = { false,false,false,false,false,false };


	if (x > 0 || x == -10) {
		if (y == 1) {
			cam6[0] = 1;
			cam6[5] = 1;
		}
		if (y == 2) {
			cam6[0] = 1;
			cam6[1] = 1;
		}
		if (y == 3) {
			cam6[4] = 1;
			cam6[5] = 1;
		}

	}
	else {

		if (y == 1) {
			cam6[2] = 1;
			cam6[3] = 1;
		}
		if (y == 2) {
			cam6[1] = 1;
			cam6[2] = 1;
		}
		if (y == 3) {
			cam6[3] = 1;
			cam6[4] = 1;
		}

	}

	std::cout << "cam61 " << cam6[0] << '\n';
	std::cout << "cam62 " << cam6[1] << '\n';
	std::cout << "cam63 " << cam6[2] << '\n';
	std::cout << "cam64 " << cam6[3] << '\n';
	std::cout << "cam65 " << cam6[4] << '\n';
	std::cout << "cam66 " << cam6[5] << '\n';



	return (cam6);
}


bool** MyCamSet::outl(int horizont[], int vertical, int pom) {

	
	std::cout << "Low UHOL horizont "<< horizont[0] << '\n';
	std::cout << "Hight UHOL horizont"<< horizont[1] << '\n';
	std::cout << " Pohlad vertikalny " << vertical << '\n';
	


	/*
	if (70 > 0){
		int pom = 1;
	inRange2(50, 130, 70,pom) ? cout << "Yes1\n" : cout << "No1\n";
	inRange2(50, 130, -70,pom) ? cout << "Yes2\n" : cout << "No2\n";

	//inRange2(horizont[0],horizont[1], x11[0], vertical) ? cout << "Yes6\n" : cout << "No6\n";
	//inRange2(horizont[0], horizont[1], x11[1], vertical) ? cout << "Yes7\n" : cout << "No7\n";
	}
	else {
		int pom = 1;
	
	}*/

	
	for (int h = 1; h <= 6; h++) {
		if (pom == 180) {

			if (h == 3) {
				inRange2(horizont[0], horizont[1], x51[1], vertical, h, pom) ? cout << "Yes3\n" : cout << "No3\n";
				inRange2(horizont[0], horizont[1], x51[0], vertical, h, pom) ? cout << "Yes-3\n" : cout << "No-3\n";
				
			}

			if (h == 5) {
				
				inRange2(horizont[0], horizont[1], x31[0], vertical, h, pom) ? cout << "Yes5\n" : cout << "No5\n";
				inRange2(horizont[0], horizont[1], x31[1], vertical, h, pom) ? cout << "Yes-5\n" : cout << "No-5\n";
			}

		
		}
		else {

		if (h == 1) {
		//	if (pom >= 0) {
				inRange2(horizont[0], horizont[1], x11[0], vertical, h,pom) ? cout << "Yes1\n" : cout << "No1\n";
				inRange2(horizont[0], horizont[1], x11[1], vertical, h, pom) ? cout << "Yes-1\n" : cout << "No-1\n";
		//	}
			//else {
		
			//inRange2(horizont[0], horizont[1], x12[0], vertical, h) ? cout << "Yes1\n" : cout << "No1\n";
			//inRange2(horizont[0], horizont[1], x12[1], vertical, h) ? cout << "Yes-1\n" : cout << "No-1\n";
		//	}
				/*
				std::cout << " nejaky vystup1 " << *(kokotina[0] + 0) << '\n';
				std::cout << " nejaky vystup2 " << *(kokotina[1] + 1) << '\n';
				std::cout << " nejaky vystup3 " << *(kokotina[2] + 2) << '\n';
				std::cout << " nejaky vystup4 " << *(kokotina[3] + 3) << '\n';
				std::cout << " nejaky vystup5 " << *(kokotina[4] + 4) << '\n';
				std::cout << " nejaky vystup6 " << *(kokotina[5] + 5) << '\n';
				*/
		}

		if (h == 2) {
			//if (pom >= 0) {
			inRange2(horizont[0], horizont[1], x21[0], vertical, h, pom) ? cout << "Yes2\n" : cout << "No2\n";
			if (pom == 45){
			inRange2(horizont[0], horizont[1], x21[2], vertical, h, pom) ? cout << "Yes-2\n" : cout << "No-2\n";
			}
			else {
				inRange2(horizont[0], horizont[1], x21[1], vertical, h, pom) ? cout << "Yes-22\n" : cout << "No-22\n";
			}
			//}
			//else {
				//inRange2(horizont[0], horizont[1], x22[0], vertical, h) ? cout << "Yes2\n" : cout << "No2\n";
			//	inRange2(horizont[0], horizont[1], x22[1], vertical, h) ? cout << "Yes-2\n" : cout << "No-2\n";

			//}
		}
		if (h == 3) {
			//if (pom < 0) {
			if (pom == 135){
			inRange2(horizont[0], horizont[1], x31[2], vertical, h, pom) ? cout << "Yes3\n" : cout << "No3\n";
			}
			else {
				inRange2(horizont[0], horizont[1], x31[0], vertical, h, pom) ? cout << "Yes3\n" : cout << "No3\n";
			}
			inRange2(horizont[0], horizont[1], x31[1], vertical, h, pom) ? cout << "Yes-3\n" : cout << "No-3\n";
			//}
		//	else {
			//	inRange2(horizont[0], horizont[1], x32[0], vertical, h) ? cout << "Yes3\n" : cout << "No3\n";
				//inRange2(horizont[0], horizont[1], x32[1], vertical, h) ? cout << "Yes-3\n" : cout << "No-3\n";
		//	}
		}


		if (h == 4) {
			//if (pom < 0) {
			inRange2(horizont[0], horizont[1], x41[0], vertical,h, pom) ? cout << "Yes4\n" : cout << "No4\n";
			inRange2(horizont[0], horizont[1], x41[1], vertical,h, pom) ? cout << "Yes-4\n" : cout << "No-4\n";
			//}
		//	else {
				//inRange2(horizont[0], horizont[1], x42[0], vertical, h) ? cout << "Yes4\n" : cout << "No4\n";
				//inRange2(horizont[0], horizont[1], x42[1], vertical, h) ? cout << "Yes-4\n" : cout << "No-4\n";
		//	}
		}

		if (h == 5) {
			//	if (pom < 0) {
			inRange2(horizont[0], horizont[1], x51[0], vertical, h, pom) ? cout << "Yes5\n" : cout << "No5\n";
			if (pom == -135) {
				inRange2(horizont[0], horizont[1], x51[2], vertical, h, pom) ? cout << "Yes5\n" : cout << "No5\n";
			}
			else {
				inRange2(horizont[0], horizont[1], x51[1], vertical, h, pom) ? cout << "Yes-5\n" : cout << "No-5\n";
			}
			
			
			
		//	}
			//else {
				//inRange2(horizont[0], horizont[1], x52[0], vertical, h) ? cout << "Yes5\n" : cout << "No5\n";
				//inRange2(horizont[0], horizont[1], x52[1], vertical, h) ? cout << "Yes-5\n" : cout << "No-5\n";
			//}
		}

		if (h == 6) {
			//if (pom >= 0) {
			if (pom == -45) {
			inRange2(horizont[0], horizont[1], x61[2], vertical, h, pom) ? cout << "Yes6\n" : cout << "No6\n";
			}
			else {
				inRange2(horizont[0], horizont[1], x61[0], vertical, h, pom) ? cout << "Yes6\n" : cout << "No6\n";
			}
			inRange2(horizont[0], horizont[1], x61[1], vertical, h, pom) ? cout << "Yes-6\n" : cout << "No-6\n";
			
			//}
			//else {
				//inRange2(horizont[0], horizont[1], x62[0], vertical, h) ? cout << "Yes6\n" : cout << "No6\n";
				//inRange2(horizont[0], horizont[1], x62[1], vertical, h) ? cout << "Yes-6\n" : cout << "No-6\n";
			//}

			
		}
		}
	}
	/*
	std::cout << " nejaky vystup00 " <<	*(&kokotina[0] + 0) << '\n';
	std::cout << " nejaky vystup00 " << *(&kokotina[3] + 3) << '\n';
	std::cout << " nejaky vystup00 " << *(kokotina[6] + 5) << '\n';
	std::cout << " nejaky vystup00 " << *(kokotina[0] + 2) << '\n';
	*/
	
	
	bool** m;
	//std::cout << " nejaky vystup00 " << &m << '\n';
	m = polesmernikov;

	//std::cout << " nejaky vystup00 " << *(kokotina[0] + 1) << '\n';
	//std::cout << " nejaky vystup00 " << (&kokotina[0] + 1) << '\n';
	/*
	std::cout << " &polesmernikov " << (&polesmernikov) << '\n';
	std::cout << " *(&m)     " << *(&m) << '\n';
	std::cout << " **(&m)    " << **(&m) << '\n';
	std::cout << " *&(*(m))  " << *&(*(m )) << '\n';
	std::cout << " *&(*(m+1))" << *&(*(m+1)) << '\n';
	std::cout << " *&(*(m+2))" << *&(*(m + 2)) << '\n';
	std::cout << " *&(*(m+3))" << *&(*(m + 3)) << '\n';
	std::cout << " *&(*(m+4))" << *&(*(m + 4)) << '\n';
	std::cout << " *&(*(m+5))" << *&(*(m + 5)) << '\n';


	std::cout << " *(*(m+1)) cam11 " << *(*(m)+0) << '\n';
	std::cout << " *(*(m)+1) cam12 " << *(*(m)+1) << '\n';
	std::cout << " *(*(m)+2) cam13 " << *(*(m)+2) << '\n';
	std::cout << " *(*(m)+3) cam14 " << *(*(m)+3) << '\n';
	std::cout << " *(*(m)+4) cam15 " << *(*(m)+4) << '\n';
	std::cout << " *(*(m)+5) cam16 " << *(*(m)+5) << '\n';
	
	std::cout << "   "  << '\n';
	std::cout << "   " << '\n';

	std::cout << " *(*(m+1)) cam21 " << *(*(m+1)+0) << '\n';
	std::cout << " *(*(m)+1) cam22 " << *(*(m+1)+1) << '\n';
	std::cout << " *(*(m)+2) cam23 " << *(*(m+1)+2) << '\n';
	std::cout << " *(*(m)+3) cam24 " << *(*(m+1)+3) << '\n';
	std::cout << " *(*(m)+4) cam25 " << *(*(m+1)+4) << '\n';
	std::cout << " *(*(m)+5) cam26 " << *(*(m+1)+5) << '\n';

	std::cout << "   " << '\n';
	std::cout << "   " << '\n';

	
	std::cout << "   " << '\n';
	std::cout << "   " << '\n';

	std::cout << " *(*(m+1))  " << *(*(m + 5) + 0) << '\n';
	std::cout << " *(*(m)+1)  " << *(*(m + 5) + 1) << '\n';
	std::cout << " *(*(m)+2)  " << *(*(m + 5) + 2) << '\n';
	std::cout << " *(*(m)+3)  " << *(*(m + 5) + 3) << '\n';
	std::cout << " *(*(m)+4)  " << *(*(m + 5) + 4) << '\n';
	std::cout << " *(*(m)+5)  " << *(*(m + 5) + 5) << '\n';
	*/
	

	return polesmernikov;

}



