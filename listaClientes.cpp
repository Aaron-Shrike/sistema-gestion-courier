// CLIENTEVIP

class Cliente{
  private:
	int codigo;
 	char pagina[LIM];
   	char dni[MAXDNI];
   	char nombre[LIM];
   	char direccion[LIM];
   	char telefono[MAXFONE];
   	char correo[LIM];

  public:
 	Cliente(){
		this->codigo = 0;
      	this->pagina[0] = NULL;
   		this->dni[0] = NULL;
      	this->nombre[0] = NULL;
      	this->direccion[0] = NULL;
		this->telefono[0] = NULL;
      	this->correo[0] = NULL;
   	}

   	void leer(){
      	cout << " > Codigo Asignado : " << this->codigo << endl;
      	cin.ignore();
      	cout << " > Pagina WEB : "; cin.getline(pagina,LIM-1);
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
      	cout << " > Correo : "; cin.getline(correo,LIM-1);
   	}

   	void mostrar(){
      	cout << "	CODIGO : " << this->codigo << endl;
   		cout << "	Pagina WEB : " << this->pagina << endl;
   		cout << "	DNI : " << this->dni << endl;
      	cout << "	Nombre : " << this->nombre << endl;
      	cout << "	Direccion : " << this->direccion << endl;
      	cout << "	Telefono : " << this->telefono << endl;
      	cout << "	Correo : " << this->correo << endl;
  	}

   	void setCodigo(int aux){
   		this->codigo = 100 + aux;
   	}

   	int getCodigo(){
   		return this->codigo;
   	}

   	void getPagina(char *aux){
   		strcpy(aux,this->pagina);
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

   void getCorreo(char *aux){
   	strcpy(aux,this->correo);
   }

};

class ListaClientes{
  private:
 	int n;
   	int max;
   	Cliente **data;

  public:
 	ListaClientes(){
   		this->n = 0;
      	this->max = 0;
      	this->data = NULL;
   	}

   	~ListaClientes(){
   		if(this->max > 0){
      		delete []this->data;
      	}
      	this->n = 0;
      	this->max = 0;
   }

   	int getN(){
   		return this->n;
   	}

   	Cliente *get(int pos){
  		return this->data[pos];
   	}

   	void agregar(Cliente *cliente){
   		if(this->n == this->max){
      		this->crecer();
      	}
      	this->data[this->n] = cliente;
      	this->n++;
   	}

   	Cliente *buscarClienteCodigo(int clienteBuscar){
      	Cliente *cliente;

		for(int i=0;i<this->getN();i++){
      		cliente = this->get(i);

         	if(clienteBuscar == cliente->getCodigo()){
            	return cliente;
         	}
      	}

      	return NULL;
   	}

  private:
 	void crecer(){
   		Cliente **aux;

      	this->max += DELTA;
      	aux = new Cliente *[this->max];

      	for(int i=0;i<this->n;i++){
      		aux[i] = this->data[i];
      	}
      	if(this->n >0){
      		delete []this->data;
      	}
      	this->data = aux;
   	}
};
