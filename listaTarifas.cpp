// TARIFAS

class Tarifa{
  private:
 	float estandar;
   	float masKilo;

  public:
 	Tarifa(){
   	 	this->estandar = 0.0;
      	this->masKilo = 0.0;
   	}

   	void leer(int & flag,int & flag1);

   	void mostrar(){
   		cout << "	Estandar : " << this->estandar << endl;
      	cout << "	Adicional : " << this->masKilo << endl;
   	}

   	float getEstandar(){
   		return this->estandar;
   	}

   	float getMasKilo(){
   		return this->masKilo;
   	}
};

class ListaTarifas{
  private:
 	int n;
   	int max;
   	Tarifa **data;

  public:
 	ListaTarifas(){
   		this->n = 0;
      	this->max = 0;
      	this->data = NULL;
   	}
   	~ListaTarifas(){
   		if(this->max > 0){
      		delete []this->data;
      	}
      	this->n = 0;
      	this->max = 0;
   	}

   	int getN(){
   		return this->n;
   	}

   	Tarifa *get(int pos){
  		return this->data[pos];
   	}

   	void agregar(Tarifa *tarifa){
   		if(this->n == this->max){
      		this->crecer();
      	}
      	this->data[this->n] = tarifa;
      	this->n++;
   	}

   	int buscarTarifaEstandar(float aux){
      	Tarifa *tarifa;

		for(int i=0;i<this->getN();i++){
      		tarifa = this->get(i);

         	if(tarifa->getEstandar() == aux){
				return 1;
         	}
      	}

      	return 0;
   	}

   	int buscarTarifaAdicional(float aux){
      	Tarifa *tarifa;

		for(int i=0;i<this->getN();i++){
      		tarifa = this->get(i);

         	if(tarifa->getMasKilo() == aux){
				return 1;
         	}
      	}

      	return 0;
   	}

  private:
 	void crecer(){
   		Tarifa **aux;

      	this->max += DELTA;
      	aux = new Tarifa *[this->max];

      	for(int i=0;i<this->n;i++){
      		aux[i] = this->data[i];
      	}
      	if(this->n >0){
      		delete []this->data;
      	}
      	this->data = aux;
   	}
};
