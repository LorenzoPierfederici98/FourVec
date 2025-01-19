#include "four_vec.h"
using namespace std;

/**
 * @file
 * @brief Project
 * 
 */

class FourVec {

	float p_x, p_y, p_z, E;
	
	public:

	/**
	 * \brief Class describing a 4-vector.
	 * 
	 */
	FourVec(float px, float py, float pz, float en) : 
		p_x(px), p_y(py), p_z(pz), E(en) {}

	FourVec(){}

	/**
	 * @brief x-component of the momemntum
	 * 
	 * @return float 
	 */
	float px(){return p_x;}
	/**
	 * @brief y-component of the momemntum
	 * 
	 * @return float 
	 */
	float py(){return p_y;}
	/**
	 * @brief z-component of the momemntum
	 * 
	 * @return float 
	 */
	float pz(){return p_z;}
	/**
	 * @brief energy
	 * 
	 * @return float 
	 */
	float e(){return E;}
	//transverse impulse and invariant mass, c==1
	/**
	 * @brief transverse component of the momentum \f(\sqrt{p_x^2 + p_y^2}\f) (c=1)
	 * 
	 * @return float 
	 */
	float pt(){return sqrt(p_x*p_x + p_y*p_y);}
	float m(){return sqrt(E*E - p_x*p_x - p_y*p_y - p_z*p_z);}
	//without the second const the operator wouldn't act on const obj
	//with the second const it acts both on const and non const obj
	FourVec operator + (const FourVec & obj) const {
		FourVec  vec(p_x + obj.p_x,  p_y + obj.p_y, p_z + obj.p_z, E + obj.E);
		return vec;
	}
	
	template <class T>
		FourVec operator * (T scalar){
			FourVec vec(scalar * p_x, scalar * p_y, scalar * p_z, scalar * E);
			return vec;
		}

	void print() { cout << "(" << p_x << ", " << p_y << ", " << p_z << ", " << E << ")" ;}
};

class Particle :  public FourVec {

	int m_PID;

	public:
		Particle(const FourVec & p4, int PID) : 
			FourVec(p4), m_PID(PID) {}
		Particle() {}
		int particleID() {return m_PID;}

};

class TwoBodiesDecayedParticle : public Particle {

	Particle m_p1;
	Particle m_p2;

   	public:
	TwoBodiesDecayedParticle(const Particle & p1, const Particle &p2,int pid=0) :
		Particle(p1+p2, pid), m_p1(p1), m_p2(p2) {}

	void print(){
		cout << "P1 mass : " << m_p1.m() << " P1 pt : " << m_p1.pt() << endl;
		cout << "P2 mass : " << m_p2.m() << " P2 pt : " << m_p2.pt() << endl;
		cout << "PDecay mass : " << m() << " PDecay pt : " << pt() << endl;
	}
};

int main(){

	cout << "Four-vector : (p_x, p_y, p_z, E) (c=1)" << endl;
	cout << "m : sqrt(E^2 - |p|^2)" << endl;
	cout << "pt : sqrt(p_x^2 + p_y^2)" << endl;
	FourVec vec(10., 10., 10., 30.), vecc(20., 4., 10., 35.);

	FourVec vecsum;
	vecsum = vec + vecc;
	
	cout << "Sum: ";
       	vec.print();
	cout << " + ";
	vecc.print();
	cout << " = ";
	vecsum.print();
	cout << endl;

	FourVec vecscal;
	int a = 2;
       	vecscal	= vec * a;

	cout << "Scal. mul. ";
	vec.print();
	cout << " * " << a << " = ";
	vecscal.print();
	cout << endl;

	//The operation between a FourVec and Particle obj can be performed
	//as a Particle obj is a FourVec obj. It outputs a FourVec obj.
	
	Particle  p1(FourVec(0., 20., 30., 50.), 1);
	Particle  p2(FourVec(0., 10., 30., 40.), 2);
	
	cout << "P1 : ";
	p1.print();
	cout << endl;
	cout << "P2 : ";
	p2.print();
	cout << endl;

	TwoBodiesDecayedParticle pi0(p1, p2);

	pi0.print();
	return 0;
}
