// CONSIGNADO :

class Consignado{
  private:
   	int auxRemito;
 	char dni[MAXDNI];
	char nombre[LIM];
   	char direccion[LIM];
   	char telefono[MAXFONE];

  public:
 	Consignado(){
      	this->auxRemito = 0;
   		this->dni[0] = NULL;
   		this->nombre[0] = NULL;
      	this->direccion[0] = NULL;
      	this->telefono[0] = NULL;
   	}

   	void leer(int aux){
      	cout << endl;
      	cout << "------- CONSIGNADO [Nro. " << (aux+1) << "] -------" << endl;
   		cout << endl;

      	do{
      		cout << " > DNI(8 digitos) : "; cin >> this->dni;
      	}while(!(strlen(this->dni) == MAXDNI-1));
      	cin.ignore();
      	cout << " > Nombre : "; cin.getline(nombre,LIM-1);
      	cout << " > Direccion : "; cin.getline(direccion,LIM-1);
      	do{
      		cout << " > Telefono(9 digitos) : "; cin >> this->telefono;
      	}while(!(strlen(this->telefono) == MAXFONE-1));
      	cin.ignore();
   	}

   	void mostrarConsignado(){
   		cout << "	DNI : " << this->dni << endl;
      	cout << "	Nombre : " << this->nombre << endl;
      	cout << "	Direccion : " << this->direccion << endl;
      	cout << "	Telefono : " << this->telefono << endl;
   	}

   	void setAuxRemito(int aux){
   		this->auxRemito = aux;
   	}

   	int getAuxRemito(){
   		return this->auxRemito;
   	}

   	void getDNI(char *aux){
   		strcpy(aux,this->dni);
   	}

   	void getNombre(char *aux){
   		strcpy(aux,this->nombre);
   	}

   	void getDireccion(char *aux){
   		strcpy(aux,this->direccion);
   	}

   	void getTelefono(char *aux){
   		strcpy(aux,this->telefono);
   	}
};

class ListaConsignados{
  private:
 	int n;
   	int max;
   	Consignado **data;

  public:
 	ListaConsignados(){
   		this->n = 0;
      	this->max = 0;
      	this->data = NULL;
   	}

   	~ListaConsignados(){
   		if(this->max > 0){
      		delete []this->data;
      	}
      	this->n = 0;
      	this->max = 0;
   	}

   	int getN(){
   		return this->n;
   	}

   	Consignado *get(int pos){
  		return this->data[pos];
   	}

   	void agregar(Consignado *consignado){
   		if(this->n == this->max){
      		this->crecer();
      	}
      	this->data[this->n] = consignado;
      	this->n++;
   	}

  private:
 	void crecer(){
   		Consignado **aux;

      	this->max += DELTA;
      	aux = new Consignado *[this->max];

      	for(int i=0;i<this->n;i++){
      		aux[i] = this->data[i];
      	}
      	if(this->n >0){
      		delete []this->data;
      	}
      	this->data = aux;
   	}
};
