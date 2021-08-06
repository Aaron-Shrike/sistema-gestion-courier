// Objeto :

class Objeto{
  private:
 	int tipoObjeto;
   	float peso;
   	char descripcion[LIM];

  public:
 	Objeto(){
   		this->tipoObjeto = 0;
      	this->peso = 0.0;
      	this->descripcion[0]=NULL;
   	}

   	void leer(int &aux,int auxTipo){
   		if(auxTipo == 1){
      		objetoNacional(aux);
      	}else{
      		objetoInternacional(aux);
      	}
   	}

   	void objetoNacional(int aux){
   		char *magnitudes[2] = {"Gramos(gr.)","Kilogramos(Kg.)"};
   		char *tipos[2] = {"Sobre","Paquete"};
      	int op;
      	int tipoObjeto;

      	cout << "--- OBJETO [Nro. " << (aux+1) << "] ---" << endl;
		cout << endl;

      	for(int i=0;i<2;i++){
      		cout << "   " << (i+1) << ". " << magnitudes[i] << endl;
      	}

      	op = leeEntero(" Opcion : ",1,2,"\t* Opcion no valida");

      	cout << endl;
      	if(op == 1){
      		this->peso = leeReal(" > Peso[1-999]: ",1.0,999.0,"\t* Peso no valido");
         	this->peso = this->peso/1000;
      	}else{
      		this->peso = leeReal(" > Peso[1-25]: ",1.0,25.00,"\t* Peso no valido");
      	}

      	if(this->peso > 1.3){
      		this->tipoObjeto = 2;
      	}else{
         	cout << endl;
      		for(int i=0;i<2;i++){
      			cout << "	" << (i+1) << ". " << tipos[i] << endl;
      		}

      		this->tipoObjeto = leeEntero(" > Tipo de Objeto : ",1,2,"	*Tipo no valida");
   		}
      	cout << endl;
      	cin.ignore();
      	cout << " > Descripcion : "; cin.getline(this->descripcion,LIM-1);
      	cout << endl;
  	}

   	void objetoInternacional(int aux){
   		char *magnitudes[2] = {"Gramos(gr.)","Kilogramos(Kg.)"};
   		char *tipos[2] = {"Sobre","Paquete"};
      	int op;
      	int tipoObjeto;

      	cout << "--- OBJETO [Nro. " << (aux+1) << "] ---" << endl;
		cout << endl;

      	for(int i=0;i<2;i++){
      		cout << "   " << (i+1) << ". " << magnitudes[i] << endl;
      	}

      	op = leeEntero(" Opcion : ",1,2,"\t* Opcion no valida");

      	cout << endl;
      	if(op == 1){
      		this->peso = leeReal(" > Peso[1-999]: ",1.0,999.0,"\t* Peso no valido");
         	this->peso = (float) this->peso/1000;
      	}else{
      		this->peso = leeReal(" > Peso[1-5]: ",1.0,5.00,"\t* Peso no valido");
      	}

      	cout << endl;
      	if(this->peso > 0.5){
      		this->tipoObjeto = 2;
     	}else{
      		for(int i=0;i<2;i++){
      			cout << "	" << (i+1) << ". " << tipos[i] << endl;
      		}

      		this->tipoObjeto = leeEntero(" > Tipo de Objeto : ",1,2,"	*Tipo no valida");
   		}

      	cout << endl;
      	cin.ignore();
      	cout << " > Descripcion : "; cin.getline(this->descripcion,LIM-1);
      	cout << endl;
   	}

   	void mostrarObjeto(){
      	char *tipos[2] = {"Sobre","Paquete"};

   		cout << "	Tipo de objeto : " << tipos[this->tipoObjeto-1] << endl;
      	cout << "	Peso : " << this->peso << " Kg." << endl;
      	cout << "	Descripcion : " << this->descripcion << endl;
   	}

   	int getTipoObjeto(){
   		return this->tipoObjeto;
   	}

   	float getPeso(){
   		return this->peso;
   	}

   	void getDescripcion(char *aux){
   		strcpy(aux,this->descripcion);
   	}
};

class ListaObjetos{
  private:
 	int n;
   	int max;
   	Objeto **data;

  public:
 	ListaObjetos(){
   		this->n = 0;
      	this->max = 0;
      	this->data = NULL;
   	}

   	~ListaObjetos(){
   		if(this->max > 0){
      		delete []this->data;
      	}
      	this->n = 0;
      	this->max = 0;
   	}

   	int getN(){
   		return this->n;
   	}

   	Objeto *get(int pos){
  		return this->data[pos];
   	}

   	void agregar(Objeto *objeto){
   		if(this->n == this->max){
      		this->crecer();
      	}
      	this->data[this->n] = objeto;
      	this->n++;
   	}

  private:
 	void crecer(){
   		Objeto **aux;

      	this->max += DELTA;
      	aux = new Objeto *[this->max];

      	for(int i=0;i<this->n;i++){
      		aux[i] = this->data[i];
      	}
      	if(this->n >0){
      		delete []this->data;
      	}
      	this->data = aux;
   	}
};
