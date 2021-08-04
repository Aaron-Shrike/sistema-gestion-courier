// COURIER

class Courier{
  private:
   	char nombre[MAX];
	char nombreEmpresa[MAX];
   	char rucEmpresa[MAXRUC];
   	char direccionEmpresa[LIM];
   	char referenciaEmpresa[LIM];
   	char departamento[MAX];
   	char direccion[LIM];

  public:
	void inicializar(){
      	this->nombre[0] = NULL;
   		this->nombreEmpresa[0] = NULL;
      	this->rucEmpresa[0] = NULL;
      	this->direccionEmpresa[0] = NULL;
      	this->referenciaEmpresa[0] = NULL;
		this->departamento[0] = NULL;
      	this->direccion[0] = NULL;
   	}

   	void leer(){
      	cout << "[+---------------- REGISTRAR COURIER ----------------+]" << endl;
      	cout << endl;
      	cin.ignore();
      	cout << " > Nombre : "; cin.getline(nombre,MAX-1);
      	cout << endl;
      	cout << " > Datos de la Empresa:" << endl;
      	cout << "	+ Nombre : "; cin.getline(nombreEmpresa,MAX-1);
      	do{
      		cout << "	+ RUC(11 digitos) : "; cin >> this->rucEmpresa;
      	}while(!(strlen(this->rucEmpresa) == MAXRUC-1));
      	cin.ignore();
   		cout << "	+ Direccion : "; cin.getline(direccionEmpresa,LIM-1);
      	cout << "	+ Referencia : "; cin.getline(referenciaEmpresa,LIM-1);
      	cout << endl;
      	cout << " > Departamento : "; cin.getline(departamento,MAX-1);
      	cout << " > Direccion : "; cin.getline(direccion,LIM-1);
   	}

   	void mostrar(){
   		cout << "			" << this->nombre << endl;
      	cout << endl;
		cout << "			" << this->nombreEmpresa << endl;
      	cout << "    RUC : " << this->rucEmpresa << " - " << this->direccionEmpresa << endl;
      	cout << "		" << this->referenciaEmpresa << endl;
      	cout << endl;
      	cout << "			" << this->departamento << endl;
      	cout << "		" << this->direccion << endl;
   	}

   	void getNombre(char *aux){
   		strcpy(aux,this->nombre);
   	}

	void getNombreEmpresa(char *aux){
   		strcpy(aux,this->nombreEmpresa);
   	}

   	void getRucEmpresa(char *aux){
   		strcpy(aux,this->rucEmpresa);
   	}

   	void getDireccionEmpresa(char *aux){
   		strcpy(aux,this->direccionEmpresa);
   	}

   	void getReferenciaEmpresa(char *aux){
   		strcpy(aux,this->referenciaEmpresa);
   	}

   	void getDepartamento(char *aux){
   		strcpy(aux,this->departamento);
   	}

   	void getDireccion(char *aux){
   		strcpy(aux,this->direccion);
   	}
};
