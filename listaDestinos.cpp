// DESTINO :

class Destino{
  private:
   	char destino[MAX];
	char abreviatura[MAX];

  public:
	Destino(){
      	this->destino[0] = NULL;
   		this->abreviatura[0] = NULL;
   	}

   	virtual void leer(){
	   	cin.getline(this->destino,MAX-1);
	   	cout << " > Abreviatura : "; cin.getline(this->abreviatura,MAX-1);
   	}

   	void mostrar(){
   		cout << "	Destino : " << this->destino << endl;
      	cout << "	Abreviatura : " << this->abreviatura << endl;
   	}

   	ListaTarifas & guardarListaTarifas();

	void leerTarifaDepartamento(float &ess, float &add){
      	int op;
		float estandar;
   		float masKilo;

      	Tarifa *tarifa;
      	ListaTarifas & tari = guardarListaTarifas();

   		cout << "    Listado de Tarifas"<<endl;
   		cout << endl;
   		cout << "	    -Estandar-	-Adicional- " <<endl;
   		for(int i=0;i<tari.getN();i++){
   			tarifa = tari.get(i);

         	estandar = tarifa->getEstandar();
         	masKilo = tarifa->getMasKilo();
         	cout << "	" << (i+1) << ".     " << estandar << "    	    " << masKilo <<endl;
		}
      	cout << endl;
   		op = leeEntero(" > Tipo de tarifa : ",1,tari.getN(),"\t* Tipo no valido");

   		tarifa = tari.get(op-1);

		ess = tarifa->getEstandar();
   		add = tarifa->getMasKilo();
   	}

   	void getDestino(char *aux){
   		strcpy(aux,this->destino);
   	}

   	void getAbreviatura(char *aux){
   		strcpy(aux,this->abreviatura);
   	}

   	virtual int getTipoDestino() = 0;
   	//1: Nacional,2: Internacional
};

class NodoDestino{
  friend class ListaDestinos;
  private:
	Destino *destino;
   	NodoDestino *sgte;

  public:
	NodoDestino(){
      	this->destino = NULL;
   		this->sgte = NULL;
   	}

   	~NodoDestino(){
   		if(this->destino != NULL){
      		delete this->destino;
      	}
   	}
};

class ListaDestinos{
  private:
	int n;
   	NodoDestino *cab;

 public:
	ListaDestinos(){
   		this->n =0;
      	this->cab = NULL;
   	}

   	~ListaDestinos(){
   		NodoDestino *temp;
      	while(this->cab != NULL){
      		temp = this->cab;
         	this->cab = temp->sgte;
         	delete temp;
      	}
      	this->n=0;
   	}

   	void agregar(Destino *destino){
   		NodoDestino *nuevo = new NodoDestino();
      	NodoDestino *ultimo;

      	nuevo->destino = destino;

      	if(this->cab == NULL){
      		this->cab = nuevo;
      	}else{
      		ultimo = this->cab;
         	while(ultimo->sgte != NULL){
         		ultimo = ultimo->sgte;
         	}
         	ultimo->sgte = nuevo;
      	}
      	this->n++;
   	}

   	int getN(){
   		return this->n;
   	}

   	Destino *get(int pos){
   		NodoDestino *temp;

      	if(pos>=0 && pos<this->n){
      		temp = this->cab;
      		for(int i=0;i<pos;i++){
         		temp = temp->sgte;
         	}
         	return temp->destino;
      	}else{
      		return NULL;
      	}
   	}

   	/*Destino *buscarDestino(char *destinoBuscar){
   		NodoDestino *temp = this->cab;
      	Destino *aux = NULL;
		char auxDepartamento[MAX];

		while(temp != NULL){
      		temp->destino.getDepartamento(auxDepartamento);

         	if(strcmpi(auxDepartamento,destinoBuscar) == 0){
            	aux = &(temp->destino);

         		return aux;
         	}
         	temp = temp->sgte;
      	}

      	return NULL;
   	}*/
};
