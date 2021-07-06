// DETALLE :

class Detalle{
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

   Fecha fDetalle;
   Tiempo tDetalle;
 	char nombre[MAX];
   char descripcion[LIM];

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

 	Detalle(){
   	iniciaFecha(this->fDetalle);
      iniciaTiempo(this->tDetalle);
   	this->nombre[0] = NULL;
      this->descripcion[0] = NULL;
   }

   void leer(){
      time_t now = time(NULL);

      struct tm time = *localtime(&now);

      this->fDetalle.dia = time.tm_mday;
      this->fDetalle.mes = time.tm_mon + 1;
      this->fDetalle.anio = time.tm_year + 1900;
      this->tDetalle.hora = time.tm_hour;
      this->tDetalle.minuto = time.tm_min;
      this->tDetalle.segundo = time.tm_sec;

      cin.ignore();
   	cout << " > Nombre: "; cin.getline(this->nombre,MAX-1);
      cout << " > Descripcion: "; cin.getline(this->descripcion,LIM-1);
   }

   void getFechaDetalle(int &auxDia,int &auxMes,int &auxAnio){
      auxDia = this->fDetalle.dia;
      auxMes = this->fDetalle.mes;
      auxAnio = this->fDetalle.anio;
   }

   void getTiempoDetalle(int &auxHora,int &auxMin,int &auxSeg){
      auxHora = this->tDetalle.hora;
      auxMin = this->tDetalle.minuto;
      auxSeg = this->tDetalle.segundo;
   }

   void getNombre(char *aux){
   	strcpy(aux,this->nombre);
   }

   void getDescripcion(char *aux){
   	strcpy(aux,this->descripcion);
   }

};

class ListaDetalles{
 private:
 	int n;
   int max;
   Detalle **data;

 public:
 	ListaDetalles(){
   	this->n = 0;
      this->max = 0;
      this->data = NULL;
   }

   ~ListaDetalles(){
   	if(this->max > 0){
      	delete []this->data;
      }
      this->n = 0;
      this->max = 0;
   }

   int getN(){
   	return this->n;
   }

   Detalle *get(int pos){
  		return this->data[pos];
   }

   void agregar(Detalle *detalle){
   	if(this->n == this->max){
      	this->crecer();
      }
      this->data[this->n] = detalle;
      this->n++;
   }

 private:
 	void crecer(){
   	Detalle **aux;

      this->max += DELTA;
      aux = new Detalle *[this->max];

      for(int i=0;i<this->n;i++){
      	aux[i] = this->data[i];
      }
      if(this->n >0){
      	delete []this->data;
      }
      this->data = aux;
   }
};