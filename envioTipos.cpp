// SERVICIOS DE ENVIO

class Regular:public Envio{
  private:
   	char destino[MAX];
   	char abreviatura[MAX];
   	int cantidadObjetos;
   	float pesoTotal;
   	float costo;

  public:
   	Regular(){
      	this->destino[0] = NULL;
      	this->abreviatura[0] = NULL;
      	this->cantidadObjetos = 0;
      	this->pesoTotal = 0.0;
      	this->costo = 0.0;
   	}

 	virtual void leer(){
      	float auxFloat;
      	float auxEstandar;
   		float auxAdicional;
      	int n;

      	cout << endl;
      	Envio::leer();

      	registrarDestino(this->destino,this->abreviatura,auxEstandar,auxAdicional);

      	cout << endl;
      	this->cantidadObjetos = leeEntero(" > Cantidad de objetos[1-8]: ",1,8,"\t* Cantidad no valida");

      	cout << endl;
      	cout << "(------- REGISTRAR OBJETOS -------)" << endl;

      	n = 0;
      	do{
      		registrarObjeto(n,1);
         	n++;
      	}while(!(n == this->cantidadObjetos));

      	n = 0;
      	registrarConsignado(n);

      	Objeto *objeto;
      	ListaObjetos & obje  = getListaObjetos();

      	for(int i=0;i<obje.getN();i++){
      		objeto = obje.get(i);

      		this->pesoTotal += objeto->getPeso();
      	}

      	n = 0;
      	if(this->pesoTotal > 1.3){
         	auxFloat = this->pesoTotal - 1.3;
         	do{
            	auxFloat--;
         		n++;
         	}while(auxFloat > 0.0);

   			this->costo = auxEstandar + (float)n * auxAdicional;
   		}else{
      		this->costo = auxEstandar;
      	}
   	}

   	void mostrarRegular(){
   		Objeto *objeto;
      	Consignado *consignado;

      	ListaObjetos & obje = getListaObjetos();
      	ListaConsignados & cons = getListaConsignados();

   		Envio::mostrar();
      	cout << endl;
      	cout << "	Destino : " << this->destino << "(" << this->abreviatura << ")" << endl;
      	cout << endl;
      	consignado = cons.get(0);
      	consignado->mostrarConsignado();
      	cout << endl;
      	for(int i=0;i<obje.getN();i++){
      		objeto = obje.get(i);

         	objeto->mostrarObjeto();
      	}
      	cout << endl;
      	cout << "	Peso total : " << this->pesoTotal << " Kg." << endl;
      	cout << "	Costo : S/. " << this->costo << endl;
   	}

   	void getDestino(char *aux){
   		strcpy(aux,this->destino);
   	}

   	void getAbreviatura(char *aux){
   		strcpy(aux,this->abreviatura);
   	}

   	int getCantidadObjetos(){
   		return this->cantidadObjetos;
   	}

   	float getPesoTotal(){
   		return this->pesoTotal;
   	}

   	float getCosto(){
   		return this->costo;
   	}

   	virtual int getTipoEnvio(){
   		return 1;
   	}
};

class Ecommerce:public Envio{
  private:
   	char destino[MAX];
   	char abreviatura[MAX];
   	float pesoTotal;
   	float costo;

  public:
   	Ecommerce(){
   		this->destino[0] = NULL;
   		this->abreviatura[0] = NULL;
   		this->pesoTotal = 0.0;
   		this->costo = 0.0;
   	}

 	virtual void leer(){
      	float auxFloat;
      	float auxEstandar;
   		float auxAdicional;
      	int n;

      	cout << endl;
      	Envio::leer();

      	registrarDestino(this->destino,this->abreviatura,auxEstandar,auxAdicional);

      	n = 0;
      	registrarObjeto(n,1);

      	n = 0;
      	registrarConsignado(n);

      	Objeto *objeto;
      	ListaObjetos & obje  = getListaObjetos();

      	objeto = obje.get(0);

      	this->pesoTotal = objeto->getPeso();

      	n = 0;
      	if(this->pesoTotal > 1.3){
         	auxFloat = this->pesoTotal - 1.3;
         	do{
            	auxFloat--;
         		n++;
         	}while(auxFloat > 0.0);

   			this->costo = auxEstandar + (float)n * auxAdicional;
   		}else{
      		this->costo = auxEstandar;
      	}
   	}

   	void mostrarEcommerce(){
   		Objeto *objeto;
      	Consignado *consignado;

      	ListaObjetos & obje = getListaObjetos();
      	ListaConsignados & cons = getListaConsignados();

   		Envio::mostrar();
      	cout << endl;
      	cout << "	Destino : " << this->destino << "(" << this->abreviatura << ")" << endl;
      	cout << endl;
      	consignado = cons.get(0);
      	consignado->mostrarConsignado();
      	cout << endl;
      	objeto = obje.get(0);
      	objeto->mostrarObjeto();
      	cout << endl;
      	cout << "	Peso total : " << this->pesoTotal << " Kg." << endl;
      	cout << "	Costo : S/. " << this->costo << endl;
   	}

   	void getDestino(char *aux){
   		strcpy(aux,this->destino);
   	}

   	void getAbreviatura(char *aux){
   		strcpy(aux,this->abreviatura);
   	}

   	float getPesoTotal(){
   		return this->pesoTotal;
   	}

   	float getCosto(){
   		return this->costo;
   	}

   	virtual int getTipoEnvio(){
   		return 2;
   	}
};

class Internacional:public Envio{
  private:
   	char destino[MAX];
   	char abreviatura[MAX];
   	float precioEstandar;
   	float precioAdicional;
   	float pesoTotal;
   	float costo;

  public:
   	Internacional(){
   		this->destino[0] = NULL;
   		this->abreviatura[0] = NULL;
      	this->precioEstandar = 0.0;
      	this->precioAdicional = 0.0;
   		this->pesoTotal = 0.0;
   		this->costo = 0.0;
   	}

 	virtual void leer(){
      	float auxFloat;
      	int n;

      	cout << endl;
      	Envio::leer();

      	registrarDestino(this->destino,this->abreviatura,this->precioEstandar,this->precioAdicional);

      	n = 0;
      	registrarObjeto(n,2);

      	n = 0;
      	registrarConsignado(n);

      	Objeto *objeto;
      	ListaObjetos & obje  = getListaObjetos();

      	objeto = obje.get(0);

      	this->pesoTotal = objeto->getPeso();

      	n = 0;
      	if(this->pesoTotal > 0.5){
         	auxFloat = this->pesoTotal - 0.5;
         	do{
            	auxFloat--;
         		n++;
         	}while(auxFloat > 0.0);

   			this->costo = this->precioEstandar + (float)n * this->precioAdicional;
   		}else{
      		this->costo = this->precioEstandar;
      	}
   	}

   	void mostrarInternacional(){
   		Objeto *objeto;
      	Consignado *consignado;

      	ListaObjetos & obje = getListaObjetos();
      	ListaConsignados & cons = getListaConsignados();

   		Envio::mostrar();
      	cout << endl;
      	cout << "	Destino : " << this->destino << "(" << this->abreviatura << ")" << endl;
      	cout << endl;
      	for(int i=0;i<cons.getN();i++){
      		consignado = cons.get(i);

         	consignado->mostrarConsignado();
      	}
      	cout << endl;
      	for(int i=0;i<obje.getN();i++){
      		objeto = obje.get(i);

         	objeto->mostrarObjeto();
      	}
      	cout << endl;
      	cout << "	Peso total : " << this->pesoTotal << " Kg." << endl;
      	cout << "	Costo : S/. " << this->costo << endl;
   	}

   	void getDestino(char *aux){
   		strcpy(aux,this->destino);
   	}

   	void getAbreviatura(char *aux){
   		strcpy(aux,this->abreviatura);
   	}

   	float getPrecioEstandar(){
   		return this->precioEstandar;
   	}

   	float getPresioAdicional(){
   		return this->precioAdicional;
   	}

   	float getPesoTotal(){
   		return this->pesoTotal;
   	}

   	float getCosto(){
   		return this->costo;
   	}

   	virtual int getTipoEnvio(){
   		return 3;
   	}
};

class Eventos:public Envio{
  private:
   	char destino[MAX];
   	char abreviatura[MAX];
   	int cantidadConsignados;
   	float pesoTotal;
   	float costo;

  public:
   	Eventos(){
      	this->destino[0] = NULL;
   		this->abreviatura[0] = NULL;
      	this->cantidadConsignados = 0;
   		this->pesoTotal = 0.0;
   		this->costo = 0.0;
   	}

 	virtual void leer(){
      	float auxFloat;
      	float auxEstandar;
   		float auxAdicional;
      	float auxPeso;
      	int auxTipo;
      	int n;

      	cout << endl;
      	Envio::leer();

      	registrarDestino(this->destino,this->abreviatura,auxEstandar,auxAdicional);

      	n = 0;
      	registrarObjeto(n,1);

      	n = 0;
     	registrarConsignado(n);
	
      	Objeto *objeto;
      	ListaObjetos & obje  = getListaObjetos();

      	objeto = obje.get(0);

      	auxPeso = objeto->getPeso();
      	auxTipo = objeto->getTipoObjeto();

      	cout << endl;
      	if(auxTipo == 1){
      		this->cantidadConsignados = leeEntero(" > Sobres[70-200] : ",70,200,"\t* Cantidad no valida");
      	}else{
      		this->cantidadConsignados = leeEntero(" > Paquetes[30-100] : ",30,100,"\t* Cantidad no valida");
      	}

      	cout << endl;
      	cout << "(------- REGISTRAR CONSIGNADOS -------)" << endl;

      	n = 0;
      	do{
      		registrarConsignado(n);;
         	n++;
      	}while(!(n == this->cantidadConsignados));

      	this->pesoTotal = (float)auxPeso * this->cantidadConsignados;

      	n = 0;
      	if(this->pesoTotal > 1.3){
         	auxFloat = this->pesoTotal - 1.3;
         	do{
            	auxFloat--;
         		n++;
         	}while(auxFloat > 0.0);

   			this->costo = auxEstandar + (float)n * auxAdicional;
   		}else{
      		this->costo = auxEstandar;
      	}
   	}

   	void mostrarEventos(){
   		Objeto *objeto;
      	Consignado *consignado;

      	ListaObjetos & obje = getListaObjetos();
      	ListaConsignados & cons = getListaConsignados();

   		Envio::mostrar();
      	cout << endl;
      	cout << "	Destino : " << this->destino << "(" << this->abreviatura << ")" << endl;
      	cout << endl;
      	for(int i=0;i<cons.getN();i++){
      		consignado = cons.get(i);

         	consignado->mostrarConsignado();
      	}
      	cout << endl;
      	for(int i=0;i<obje.getN();i++){
      		objeto = obje.get(i);

         	objeto->mostrarObjeto();
      	}
      	cout << endl;
      	cout << "	Peso total : " << this->pesoTotal << " Kg." << endl;
      	cout << "	Costo : S/. " << this->costo << endl;
   	}

   	void getDestino(char *aux){
   		strcpy(aux,this->destino);
   	}

   	void getAbreviatura(char *aux){
   		strcpy(aux,this->abreviatura);
   	}

   	int getCantidadConsignados(){
   		return this->cantidadConsignados;
   	}

   	float getPesoTotal(){
   		return this->pesoTotal;
   	}

   	float getCosto(){
   		return this->costo;
   	}

   	virtual int getTipoEnvio(){
   		return 4;
   	}
};
