#include <iostream>
using namespace std;

int main() {
    int total,i,j,sueldo_mayor=0;
    
    cout<<"Ingrese el numero de empleados del club: ";
    cin>>total;
    
    long codigo[total];
    string nombre[total];
    double data[total][3];
    cout<<"\nIngrese los datos de los empleados: \n";
    for(i=0;i<total;i++){
    	cout<<"EMPLEADO n."<<i+1<<":";
    	cout<<"\nCodigo: ";
    	cin>>codigo[i];
    	cout<<"Nombre: ";
    	cin>>nombre[i];
    	cout<<"Talla: ";
    	cin>>data[i][0];
    	cout<<"Peso: ";
    	cin>>data[i][1];
    	cout<<"Sueldo: ";
    	cin>>data[i][2];
    	cout<<endl;
	}
    
    cout<<"\nDatos de los empleados del club";
    cout<<"\nCODIGO\t\tNOMBRE\t\tTALLA\t\tPESO\t\tSUELDO\n";
    for(i=0;i<total;i++){
    	cout<<"\n"<<codigo[i]<<"\t\t"<<nombre[i]<<"\t\t"<<data[i][0]<<"\t\t"<<data[i][1]<<"\t\t"<<data[i][2];
    	if(data[i][2]>1000){
		sueldo_mayor++;
		}
	}
    cout<<"\nEl total de trabajadores es: "<<total;
    cout<<"\nEl numero de trabajadores con el sueldo mayor a s/.1000 es: "<<sueldo_mayor;
    
    long codi_aux;
    string nomb_aux;
    double tall_aux, peso_aux, sueldo_aux;
    
    for(i=0;i<total-1;i++){
    	for(j=i+1;j<total;j++){
    		if(codigo[i]<codigo[j]){
    			codi_aux=codigo[j];
    			codigo[j]=codigo[i];
    			codigo[i]=codi_aux;
    			
    			nomb_aux=nombre[j];
    			nombre[j]=nombre[i];
    			nombre[i]=nomb_aux;
    			
    			tall_aux=data[j][0];
    			data[j][0]=data[i][0];
    			data[i][0]=tall_aux;
    			
    			peso_aux=data[j][1];
    			data[j][1]=data[i][1];
    			data[i][1]=peso_aux;
    			
    			sueldo_aux=data[j][2];
    			data[j][2]=data[i][2];
    			data[i][2]=sueldo_aux;
			}
		}
	}
    
    cout<<"\nDatos de los empleados del club ordenados en forma descendente por su codigo";
    cout<<"\nCODIGO\t\tNOMBRE\t\tTALLA\t\tPESO\t\tSUELDO\n";
    for(i=0;i<total;i++){
    	cout<<"\n"<<codigo[i]<<"\t\t"<<nombre[i]<<"\t\t"<<data[i][0]<<"\t\t"<<data[i][1]<<"\t\t"<<data[i][2];
	}
    return 0;
}

