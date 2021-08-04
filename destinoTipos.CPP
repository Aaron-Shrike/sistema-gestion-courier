// Tipos de destino

class DestinoNacional:public Destino{
  private:
  	float tarifaEstandar;
   	float tarifaAdicional;

  public:
 	DestinoNacional(){
   		this->tarifaEstandar = 0.0;
      	this->tarifaAdicional = 0.0;
   	}

   	virtual void leer(){
   		cout << endl;
   		cout << "[---------- NUEVO DEPARTAMENTO ----------]" << endl;
	   	cout << endl;
	   	cin.ignore();
      	cout << " > Departamento : ";
      	Destino::leer();
      	cout << endl;
      	leerTarifaDepartamento(this->tarifaEstandar,this->tarifaAdicional);
   	}

   	void mostrarDestinoNacional(){
      	Destino::mostrar();
   		cout << "	Estandar : " << this->tarifaEstandar << endl;
      	cout << "	Adicional : " << this->tarifaAdicional << endl;
   	}

   	float getTarifaEstandar(){
   		return this->tarifaEstandar;
   	}

   	float getTarifaAdicional(){
   		return this->tarifaAdicional;
   	}

   	virtual int getTipoDestino(){
   		return 1;
   	}
};

class DestinoInternacional:public Destino{
  private:
	char codPostal[MAX];

  public:
   	DestinoInternacional(){
   		this->codPostal[0] = NULL;
   	}

   	virtual void leer(){
   		cout << endl;
   		cout << "[--------- REGISTRAR PAIS ---------]" << endl;
	   	cout << endl;
	   	cin.ignore();
      	cout << " > Pais : ";
      	//cout << " > Estado/Provincia: ";
      	Destino::leer();
      	cout << " > Codigo postal : "; cin.getline(this->codPostal,MAX-1);
   	}

   	void mostrarDestinoInternacional(){
      	Destino::mostrar();
      	cout << "	Codigo Postal : " << this->codPostal << endl;
   	}

   	void getCodPostal(char *aux){
   		strcpy(this->codPostal,aux);
   	}

   	virtual int getTipoDestino(){
   		return 2;
   	}
};
