// ENVIO :

class Envio{
 private:
   struct Fecha{
   	int dia;
      int mes;
      int anio;
   };

   struct Tiempo{
		int hora;
      int minuto;
      int segundo;
	};

   Fecha fRegistro;
   Fecha fRuta;
   Fecha fLlegada;
   Tiempo tRegistro;
	Tiempo tRuta;
   Tiempo tLlegada;
   int numRemito;
   int estado;
   char dignatario[LIM];
   //Remitente
   char dni[MAXDNI];
	char nombre[LIM];
   char direccion[LIM];
   char telefono[MAXFONE];
   char correo[LIM];
   //Listas
 	ListaDetalles detalles;
   ListaObjetos objetos;
   ListaConsignados consignados;

 public:

   void iniciaFecha(Fecha &F){
   	F.dia = 0;
      F.mes = 0;
      F.anio = 0;
   }

   void iniciaTiempo(Tiempo &T){
   	T.hora = 0;
      T.minuto = 0;
      T.segundo = 0;
   }

	Envio(){
      iniciaFecha(this->fRegistro);
      iniciaFecha(this->fRuta);
      iniciaFecha(this->fLlegada);
      iniciaTiempo(this->tRegistro);
      iniciaTiempo(this->tRuta);
      iniciaTiempo(this->tLlegada);
      this->numRemito = 0;
      this->estado = 0;
      this->dignatario[0] = NULL;
      this->dni[0] = NULL;
   	this->nombre[0] = NULL;
      this->direccion[0] = NULL;
      this->telefono[0] = NULL;
      this->correo[0] = NULL;
   }

   virtual void leer(){
   	time_t now = time(NULL);

      struct tm time = *localtime(&now);

      this->fRegistro.dia = time.tm_mday;
      this->fRegistro.mes = time.tm_mon + 1;
      this->fRegistro.anio = time.tm_year + 1900;
      this->tRegistro.hora = time.tm_hour;
      this->tRegistro.minuto = time.tm_min;
      this->tRegistro.segundo = time.tm_sec;

      cout << endl;
   	//cout << "(--------- REGISTRAR DIGNATARIO ---------)" << endl;
   	//cout << endl;

      cout << " > Nro. Remito asignado: " << this->numRemito << endl;
      cout << " > Dignatario: "; cin.getline(this->dignatario,LIM-1);

      cout << endl;
   	cout << "(--------- REGISTRAR REMITENTE ---------)" << endl;
   	cout << endl;

      if(getTipoEnvio() != 2){

      	do{
      		cout << " > DNI: "; cin >> this->dni;
      	}while(!(strlen(this->dni) == MAXDNI-1));
      	cin.ignore();
   		cout << " > Nombre: "; cin.getline(this->nombre,LIM-1);
      	cout << " > Direccion: "; cin.getline(this->direccion,LIM-1);
      	do{
      		cout << " > Telefono: "; cin >> this->telefono;
      	}while(!(strlen(this->telefono) == MAXFONE-1));
      	cin.ignore();
      	cout << " > Correo: "; cin.getline(this->correo,LIM-1);

         cout << endl;
   		cout << " * REMITENTE registrado exitosamente" << endl;
      }else{
         int auxCodigo;

      	Cliente *cliente;
         ListaClientes & clie = guardarListaClientes();

         auxCodigo = leeEntero(" > Codigo de cliente: ",100,200," *Codigo no valido"); 
         cliente = clie.buscarClienteCodigo(auxCodigo);

         if(cliente != NULL){

         	cliente->getDNI(this->dni);
         	cliente->getNombre(this->nombre);
         	cliente->getDireccion(this->direccion);
         	cliente->getTelefono(this->telefono);
         	cliente->getCorreo(this->correo);

            cout << endl;
   			cout << " * REMITENTE registrado exitosamente" << endl;
         }else{
            cout << endl;
         	cout << " * Cliente no encontrado" << endl;
         }
      }

   }

   void mostrar(){

      cout << "	Nro. Remito: " << this->numRemito << endl;
      cout << "	Dignatario: " << this->dignatario << endl;
      cout << endl;
   	cout << "	DNI: " << this->dni << endl;
      cout << "	Nombre: " << this->nombre << endl;
      cout << "	Direccion: " << this->direccion << endl;
      cout << "	Telefono: " << this->telefono << endl;
      cout << "	Correo: " << this->correo << endl;
   }

   ListaDestinos & guardarListaDestinos();

   ListaClientes & guardarListaClientes();

   void registrarDestino(char *aux,char *aux1,float &ess,float &add){
      char auxDestino[MAX];
      char auxAbreviatura[MAX];
      int op;
      int flag = 0;

      Destino *destino;
      ListaDestinos  & dest = guardarListaDestinos();

   	cout << endl;
      cout << "    Listado de Destinos" << endl;
      cout << endl;

      for(int i=0;i<dest.getN();i++){
      	destino = dest.get(i);

         destino->getDestino(auxDestino);

         cout << "	" << (i+1) << ". " << auxDestino << endl;
      }

      do{
         cout << endl;
      	op = leeEntero(" Opcion: ",1,dest.getN()," *Opcion no valida");

      	destino = dest.get(op-1);

      	if(getTipoEnvio() != 3){
         	if(destino->getTipoDestino() == 1){
            	flag = 1;
            }
      	}else{
         	if(destino->getTipoDestino() == 2){
            	flag = 1;
            }
         }

         if(flag == 0){
         	cout << endl;
            cout << " * Destino no correspondiente" << endl;
         }
      }while(!(flag == 1));

      destino->getDestino(auxDestino);
      destino->getAbreviatura(auxAbreviatura);

      strcpy(aux,auxDestino);
      strcpy(aux1,auxAbreviatura);

      if(destino->getTipoDestino() == 1){
      	ess = ((DestinoNacional *)destino)->getTarifaEstandar();
         add = ((DestinoNacional *)destino)->getTarifaAdicional();
   	}else{
      	cout << endl;
         ess = leeReal(" > Precio Estandar: ",60.0,300.0," *Precio no valido");
         add = leeReal(" > Precio Adicional: ",20.0,100.0," *Precio no valido");
      }
   }

   void registrarObjeto(int &aux,int aux1){
		Objeto *objeto = new Objeto();

      ListaObjetos & obje = getListaObjetos();

   	cout << endl;
   	objeto->leer(aux,aux1);
   	obje.agregar(objeto);

   	cout << endl;
   	cout << " * OBJETO registrado exitosamente" << endl;
	}

   void registrarConsignado(int &aux){
   	Consignado *consignado = new Consignado();

   	ListaConsignados & cons = getListaConsignados();

      consignado->setAuxRemito(getNumeroRemito());
      consignado->leer(aux);
      cons.agregar(consignado);

      cout << endl;
      cout << " * CONSIGNADO registrado exitosamente" << endl;
   }


   //SET
   void setFechaRuta(){
   	time_t now = time(NULL);

      struct tm time = *localtime(&now);

      this->fRuta.dia = time.tm_mday;
      this->fRuta.mes = time.tm_mon + 1;
      this->fRuta.anio = time.tm_year + 1900;
   }

   void setFechaLlegada(){
      time_t now = time(NULL);

      struct tm time = *localtime(&now);

      this->fLlegada.dia = time.tm_mday;
      this->fLlegada.mes = time.tm_mon + 1;
      this->fLlegada.anio = time.tm_year + 1900;
   }

   void setTiempoRuta(){
   	time_t now = time(NULL);

      struct tm time = *localtime(&now);

      this->tRuta.hora = time.tm_hour;
      this->tRuta.minuto = time.tm_min;
      this->tRuta.segundo = time.tm_sec;
   }

   void setTiempoLlegada(){
      time_t now = time(NULL);

      struct tm time = *localtime(&now);

      this->tLlegada.hora = time.tm_hour;
      this->tLlegada.minuto = time.tm_min;
      this->tLlegada.segundo = time.tm_sec;
   }

   void setNumeroRemito(int aux){
   	this->numRemito = 10000 + aux;
   }

   void setEstado(int aux){
   	this->estado = aux;
   }


   //Get
   void getFechaRegistro(int &auxDia,int &auxMes,int &auxAnio){
      auxDia = this->fRegistro.dia;
      auxMes = this->fRegistro.mes;
      auxAnio = this->fRegistro.anio;
   }

   void getFechaRuta(int &auxDia,int &auxMes,int &auxAnio){
      auxDia = this->fRuta.dia;
      auxMes = this->fRuta.mes;
      auxAnio = this->fRuta.anio;
   }

   void getFechaLlegada(int &auxDia,int &auxMes,int &auxAnio){
      auxDia = this->fLlegada.dia;
      auxMes = this->fLlegada.mes;
      auxAnio = this->fLlegada.anio;
   }

   void getTiempoRegistro(int &auxHora,int &auxMin,int &auxSeg){
      auxHora = this->tRegistro.hora;
      auxMin = this->tRegistro.minuto;
      auxSeg = this->tRegistro.segundo;
   }

   void getTiempoRuta(int &auxHora,int &auxMin,int &auxSeg){
      auxHora = this->tRuta.hora;
      auxMin = this->tRuta.minuto;
      auxSeg = this->tRuta.segundo;
   }

   void getTiempoLlegada(int &auxHora,int &auxMin,int &auxSeg){
      auxHora = this->tLlegada.hora;
      auxMin = this->tLlegada.minuto;
      auxSeg = this->tLlegada.segundo;
   }

   int getNumeroRemito(){
   	return this->numRemito;
   }

   int getEstado(){
   	return this->estado;
   }

   void getDignatario(char *aux){
   	strcpy(aux,this->dignatario);
   }

   //GetRemitente
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

   //GetListas
   ListaDetalles & getListaDetalles(){
   	return this->detalles;
   }

   ListaObjetos & getListaObjetos(){
   	return this->objetos;
   }

   ListaConsignados & getListaConsignados(){
   	return this->consignados;
   }

   virtual int getTipoEnvio() = 0;
   //1: Regular,2: Ecommerce,3: Internacional,4: Eventos, 5: Tramites

};

class NodoEnvio{
 friend class ListaEnvios;
 private:
	Envio *envio;
   NodoEnvio *sgte;

 public:
	NodoEnvio(){
      this->envio = NULL;
   	this->sgte = NULL;
   }

   ~NodoEnvio(){
   	if(this->envio != NULL){
      	delete this->envio;
      }
   }
};

class ListaEnvios{
 private:
	int n;
   NodoEnvio *cab;

 public:
	ListaEnvios(){
   	this->n=0;
      this->cab=NULL;
   }

   ~ListaEnvios(){
   	NodoEnvio *temp;

      while(this->cab != NULL){
      	temp = this->cab;

         this->cab = temp->sgte;
         delete temp;
      }
      this->n=0;
   }

   void agregar(Envio *envio){
   	NodoEnvio *nuevo = new NodoEnvio();
      NodoEnvio *ultimo;

      nuevo->envio = envio;

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

   Envio *get(int pos){
   	NodoEnvio *temp;

      if(pos>=0 && pos<this->n){
         temp = this->cab;

      	for(int i=0;i<pos;i++){

         	temp = temp->sgte;
         }
         return temp->envio;
      }else{
      	return NULL;
      }
   }

   Envio *buscarEnvioPorRemito(int remitoBuscar){
   	NodoEnvio *temp = this->cab;
		int auxRemito;

		while(temp != NULL){
      	auxRemito = temp->envio->getNumeroRemito();

         if(auxRemito == remitoBuscar){

         	return temp->envio;
         }
         temp = temp->sgte;
      }

      return NULL;
   }
};
