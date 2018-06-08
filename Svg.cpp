#include <fstream>
#include <iostream>
#include "Svg.h"
#include <string>
//#include "Diccionario.h"
using namespace std;

Svg::Svg(){};


void Svg::crearSvg(){
	string entrada;
	cin >> entrada;
	int longitud;
	for(int y = 1; y < 99; ++y){
		if(!(entrada[y])){
			longitud = y;
			y = 98;
		}
	}
    std::ofstream archivo("salida.svg");
    archivo << "<svg  xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\">\n";
	for(int f = 1; f <= longitud ; ++f){
		for(int i = 0; i < 34; ++i){
			archivo << "<text y=\"" << f * 3.9 * 19 << "\"  x=\"" << 30 + 55 * i << "\"> " << i <<"</text>";
			archivo << "<rect y=\"" << f * 3 * 25 <<"\" x=\"" << 10 + 55 * i << "\" height=\"50\" width=\"50\" style=\"stroke:#ff0000; fill:#ffffff\"/>";
			
			if(tolower(entrada[f-1]) == (char)(i +97)){
				if(f == 1 || f == 2){
						archivo << "<text y=\"" << f * 3 * 31 << "\" x=\"" << 30 + 55 * i << "\" style=\"fill:#ff0000;\"> " << 'X' <<"</text>";
					}
					else{
						if(f > 8){
							archivo << "<text y=\"" << f * 4.8 * 16 << "\" x=\"" << 30 + 55 * i << "\" style=\"fill:#ff0000;\"> " << 'X' <<"</text>";
						}
						else{
							archivo << "<text y=\"" << f * 5 * 16 << "\" x=\"" << 30 + 55 * i << "\" style=\"fill:#ff0000;\"> " << 'X' <<" </text>";
						}
					}
			}
			/* else{
				if(diccionario[entrada]){
					if(f == 1 || f == 2){
						archivo << "<text y=\"" << f * 3 * 31 << "\" x=\"" << 30 + 55 * i << "\"> " << 'X' <<"</text>";
					}
					else{
						if(f > 8){
							archivo << "<text y=\"" << f * 4.8 * 16 << "\" x=\"" << 30 + 55 * i << "\" > " << 'X' <<"</text>";
						}
						else{
							archivo << "<text y=\"" << f * 5 * 16 << "\" x=\"" << 30 + 55 * i << "\" > " << 'X' <<" </text>";
						}
					}
				}	 */
				else{
					if(f == 1 || f == 2){
						archivo << "<text y=\"" << f * 3 * 31 << "\" x=\"" << 30 + 55 * i << "\"> " << 'O' <<"</text>";
					}
					else{
						if(f > 8){
							archivo << "<text y=\"" << f * 4.8 * 16 << "\" x=\"" << 30 + 55 * i << "\"> " << 'O' <<"</text>";
						}
						else{
							archivo << "<text y=\"" << f * 5 * 16 << "\" x=\"" << 30 + 55 * i << "\" > " << 'O' <<" </text>";
						}
					}
				}
			//}
			  
		}
    }
	archivo << "</svg>";
}	