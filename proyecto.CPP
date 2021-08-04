#include "aFunciones.cpp"

#define MAXRUC 12
#define MAXDNI 9
#define MAXFONE 10

#define DELTA 2

#include "courier.CPP"
#include "listaTarifas.CPP"
#include "listaDestinos.CPP"
#include "destinoTipos.CPP"
#include "listaClientes.CPP"

	#include "listaDetalles.CPP"
   #include "listaObjetos.CPP"
	#include "listaConsignados.CPP"
#include "listaEnvios.CPP"

#include "envioTipos.CPP"

int flag = 0,flag1 = 0,flag2 = 0,flag3 = 0;

Courier uno;
ListaTarifas dos;
ListaDestinos tres;
ListaClientes cuatro;
ListaEnvios cinco;

//PARA: Leer Destino
ListaTarifas & Destino::guardarListaTarifas(){
	return dos;
}

//PARA: Leer Envio
ListaDestinos & Envio::guardarListaDestinos(){
	return tres;
}

//PARA: Leer Envio
ListaClientes & Envio::guardarListaClientes(){
	return cuatro;
}

void Tarifa::leer(int & flag,int & flag1){
    float auxEstandar,auxMasKilo;

   	cout << endl;
   	cout << "[------------- TARIFA NACIONAL -------------]" << endl;
    cout << endl;
    cout << " > Precios:" << endl;
    auxEstandar = leeReal("	+ Estandar[7.00-16.00] : ",7.00,16.00,"\t* Precio no valido");
    flag = dos.buscarTarifaEstandar(auxEstandar);
    auxMasKilo = leeReal("	+ Adicional[1.50-7.50] : ",1.50,7.50,"\t* Precio no valido");
    flag1 = dos.buscarTarifaAdicional(auxMasKilo);
    
    if(flag == 1 && flag1 == 1){
        cout << "\t* Tarifa registrada anteriorente" << endl;
    }else{
      	this->estandar = auxEstandar;
        this->masKilo = auxMasKilo;
    }
}

// LISTA DE MENU

int leerOpcion(){
	char *opciones[9]={"Registrar Courier","Registrar Tarifas","Registrar Destinos","Registrar Clientes",
   		"Registrar Envios","Registrar Detalle de envio","Actualizacion de estado","Listar Reportes",
        "Salir"};
   	int op;

   	for(int i=0;i<9;i++){
		cout << "   [" << (i+1) << "] " << opciones[i] << endl;
   	}
	
	op = leeEntero("	> Opcion : ",1,9,"\t* Opcion no valida");

   	return op;
}

int leerReporte(){
	char *reportes[9]={"Datos de registrados","Lista de envios","Listado de Destinos segun tipo",
		"Listado de Objetos segun tipo de Envio","Listado de Consignados segun tipo de Envio",
      	"Estadistica de Objetos","Simulacion de boleta","Consultar estado del envio","Retornar"};
   	int rep;

   	for(int i=0;i<9;i++){
   		cout << "   (" << (i+1) << ") " << reportes[i] << endl;
   	}

	rep = leeEntero(" Opcion : ",1,9,"\t* Opcion no valida");

   	return rep;
}

int leerDatos(){
	char *datos[6]={"Datos de la Courier","Listado de Tarifas",
		"Listado de Destinos","Listado de Clientes","Listado de Envios","Retornar"};
   	int dat;

   	for(int i=0;i<6;i++){
		cout << "   (" << (i+1) << ") " << datos[i] << endl;
   	}

	dat = leeEntero(" Opcion : ",1,6,"\t* Opcion no valida");

   	return dat;
}

//TIPO DE DESTINO:
int leerTipoDestino(){
	char *tipos[2]={"Nacional","Internacional"};
   	int tipo;

   	cout << endl;

   	for(int i=0;i<2;i++){
		cout << "	(" << (i+1) << ") "<< tipos[i] << endl;
   	}

   	tipo = leeEntero(" > Tipo de destino : ",1,2,"\t* Tipo no valido");

   	return tipo;
}

Destino *crearDestino(int tipo){
	Destino *d = NULL;

   	switch(tipo){
   		case 1: d = new DestinoNacional(); break;
      	case 2: d = new DestinoInternacional(); break;
   	}

   	return d;
}

// TIPO DE ENVIO :
int leerTipoEnvio(){
	char *tipos[5]={"Regular","E-commerce","Internacional","Eventos","Cancelar"};
   	char auxDepartamento[MAX];
   	int tipo;

   	uno.getDepartamento(auxDepartamento);

   	cout << endl;

   	for(int i=0;i<5;i++){
   		cout << "	(" << (i+1) << ") "<< tipos[i] << endl;
   	}

   	tipo = leeEntero(" > Tipo de envio : ",1,5,"\t* Tipo no valido");

   	if(tipo == 2){
   		if(strcmpi(auxDepartamento,"Lima") != 0){
      		tipo = 5;

         	cout << endl;
         	cout << "\t * Servicio exclusivo para el departamento de LIMA *" << endl;
      	}
   	}

  	return tipo;
}

Envio *crearEnvio(int tipo){
	Envio *e = NULL;

   	switch(tipo){
   		case 1: e = new Regular(); break;
      	case 2: e = new Ecommerce(); break;
      	case 3: e = new Internacional(); break;
      	case 4: e = new Eventos(); break;
   	}

   	return e;
}

// 8.1: MOSTRAR DATOS REGISTRADOS

// 8.1.1: Datos Courier
void courierRegistrada(){
	uno.mostrar();
   	getch();
}

// 8.1.2: Datos Tarifas
void tarifasRegistradas(){
	Tarifa *tarifa;

   	cout << endl;
   	cout << "------------- Listado de Tarifas -------------" <<endl;
   	cout << endl;

   	for(int i=0;i<dos.getN();i++){
   		tarifa = dos.get(i);

      	cout << endl;
      	cout << "Tarifa Nro." << (i+1) << " :" << endl;
      	cout << endl;

      	tarifa->mostrar();
   	}

   	cout << endl;
   	cout << "----------------------------------------------" <<endl;
	getch();
}

// 8.1.3: mostrarDestinos
void destinosRegistrados(){
   	char *tipos[2] = {"Nacional","Internacional"};
   	int tipoDestino;

	Destino *destino;

   	cout << endl;
   	cout << "------------- Listado de Destinos ------------" <<endl;
   	cout << endl;

   	for(int i=0;i<tres.getN();i++){
   		destino = tres.get(i);

      	tipoDestino = destino->getTipoDestino();

      	cout << endl;
      	cout << "Destino Nro." << (i+1) << " (" << tipos[tipoDestino-1] << ") : " << endl;
      	cout << endl;

   		switch(tipoDestino){
      		case 1: ((DestinoNacional *)destino)->mostrarDestinoNacional();
         		break;
         	case 2: ((DestinoInternacional *)destino)->mostrarDestinoInternacional();
         		break;
      	}
   	}

   	cout << endl;
   	cout << "----------------------------------------------" <<endl;
	getch();
}

// 8.1.4: mostrarClientes
void clientesRegistrados(){
   	Cliente *cliente;

	cout << endl;
   	cout << "----------------- Listado de Clientes ----------------" <<endl;

   	if(cuatro.getN() != 0){
   		for(int i=0;i<cuatro.getN();i++){
   			cliente = cuatro.get(i);

      		cout << endl;
      		cout << "Cliente Nro." << (i+1) << " :" << endl;
      		cout << endl;

      		cliente->mostrar();
   		}
   	}else{
   		cout << endl;
      	cout << "\t* No hay CLIENTES registrados *" << endl;
   	}

   	cout << endl;
   	cout << "------------------------------------------------------" <<endl;
	getch();
}

// 8.1.5: mostrarEnvios
void enviosRegistrados(){
   	char *tipos[4] = {"Regular","E-commerce","Internacional","Eventos"};
   	int tipoEnvio;

   	Envio *envio;

	cout << endl;
   	cout << "------------------ Listado de Envios -----------------" <<endl;

   	for(int i=0;i<cinco.getN();i++){
   		envio = cinco.get(i);

      	tipoEnvio = envio->getTipoEnvio();

      	cout << endl;
      	cout << "Envio Nro." << (i+1) << " (" << tipos[tipoEnvio-1] << ") : " << endl;
      	cout << endl;

   		switch(tipoEnvio){
      		case 1: ((Regular *)envio)->mostrarRegular();
         		break;
         	case 2: ((Ecommerce *)envio)->mostrarEcommerce();
         		break;
         	case 3: ((Internacional *)envio)->mostrarInternacional();
         		break;
         	case 4: ((Eventos *)envio)->mostrarEventos();
         		break;
      	}
   	}

   	cout << endl;
   	cout << "--------------------------------------------------------" <<endl;
	getch();
}

// 8. **REPORTES :

// 8.1: Datos registrados
void datosRegistrados(){
	int dat;

	do{
      	system("cls");
  		cout<<"(----------- DATOS COURIER -----------)"<<endl;

  		dat = leerDatos();

   		switch(dat){
   			case 1: courierRegistrada(); break;
      		case 2: tarifasRegistradas(); break;
      		case 3: destinosRegistrados(); break;
         	case 4: clientesRegistrados(); break;
         	case 5: enviosRegistrados(); break;
         	case 6: break;
   		}
  	}while(dat < 6);
}

// 8.2: Listado de Envios
void listaEnvios(){
   	char *tipos[4] = {"Regular","E-commerce","Internacional","Evento"};
	char nombre[LIM];
   	char dni[MAXDNI];
   	char abreviatura[MAX];
   	int tipoEnvio;

   	Envio *envio;

   	//mostrar dni, nombre, tipo de envio y destino
   	cout << endl;
   	cout << "----------------- Listado de Envios -----------------" <<endl;

   	for(int i=0;i<cinco.getN();i++){
      	envio = cinco.get(i);

      	envio->getDNI(dni);
      	envio->getNombre(nombre);
      	tipoEnvio = envio->getTipoEnvio();

      	switch(tipoEnvio){
      		case 1: ((Regular *)envio)->getAbreviatura(abreviatura);
         		break;
         	case 2: ((Ecommerce *)envio)->getAbreviatura(abreviatura);
         		break;
         	case 3: ((Internacional *)envio)->getAbreviatura(abreviatura);
         		break;
         	case 4: ((Eventos *)envio)->getAbreviatura(abreviatura);
         		break;
      	}

      	cout << endl;
      	cout << "  " << (i+1) << ".- " << dni << "   " << nombre << "   "
      		<< tipos[tipoEnvio-1] << "(" << abreviatura << ")" << endl;
   	}

   	cout << endl;
  	cout << "-----------------------------------------------------" <<endl;
	getch();
}

// 8.3: Lista de Destinos segun tipo(Nacional e Internacional)
void listaDestinosSegunTipo(){
   	char *tipos[2] = {"Nacional","Internacional"};
	char auxDestino[MAX];
   	int n = 0;
   	int auxTipo;

   	Destino *destino;

   	cout << endl;

   	for(int i=0;i<2;i++){
   		cout << "	(" << (i+1) << ") "<< tipos[i] << endl;
   	}

   	auxTipo = leeEntero(" Opcion : ",1,2,"\t* Opcion no valida");

   	cout << endl;
   	cout << "----- Listado de Destinos (" << tipos[auxTipo-1] << ") -----" <<endl;
   	cout << endl;

   	for(int i=0;i<tres.getN();i++){
   		destino = tres.get(i);

   		if(destino->getTipoDestino() == auxTipo){
      		destino->getDestino(auxDestino);

         	cout << "	(" << (n+1) << ") " << auxDestino << endl;
         	n++;
   		}
   	}

   	if(n == 0){
   		cout << endl;
      	cout << "\t* No hay DESTINOS registrados *" << endl;
   	}

   	cout << endl;
   	cout << "----------------------------------------------" <<endl;
	getch();
}

// 8.4: Listado de objetos segun tipo de Envio
void listaObjetosSegunEnvio(){
   	char *tipos[4] = {"Regular","E-commerce","Internacional","Eventos"};
	char auxDescripcion[LIM];
   	float auxPeso;
   	int n = 0;
   	int auxTipo;

   	Envio *envio;
   	Objeto *objeto;

   	cout << endl;

   	for(int i=0;i<4;i++){
   		cout << "	(" << (i+1) << ") "<< tipos[i] << endl;
   	}

   	auxTipo = leeEntero(" Opcion : ",1,4,"\t* Opcion no valida");

   	cout << endl;
   	cout << "-------- Listado de Objetos (" << tipos[auxTipo-1] << ") --------" <<endl;
   	cout << endl;

   	for(int i=0;i<cinco.getN();i++){
   		envio = cinco.get(i);

   		if(envio->getTipoEnvio() == auxTipo){
         	ListaObjetos & obje = envio->getListaObjetos();

      		for(int j=0;j<obje.getN();j++){
            	objeto = obje.get(j);

            	objeto->getDescripcion(auxDescripcion);
            	auxPeso = objeto->getPeso();

         		cout << "	" << (n+1) << ".- " << auxDescripcion << "(" << auxPeso << ")" << endl;
         		n++;
      		}
   		}
   	}

   	if(n == 0){
   		cout << endl;
      	cout << "\t* No hay OBJETOS registrados en este tipo*" << endl;
   	}

   	cout << endl;
   	cout << "--------------------------------------------------" <<endl;
	getch();
}

// 8.5: Listado de consignados segun tipo de Envio
void listaConsignadosSegunEnvio(){
	char *tipos[4] = {"Regular","E-commerce","Internacional","Eventos"};
	char auxNombre[LIM];
   	char auxDNI[MAXDNI];
   	int n = 0;
   	int auxTipo;

   	Envio *envio;
   	Consignado *consignado;

   	cout << endl;

   	for(int i=0;i<4;i++){
   		cout << "	(" << (i+1) << ") "<< tipos[i] << endl;
   	}

   	auxTipo = leeEntero(" Opcion : ",1,4,"\t* Opcion no valida");

   	cout << endl;
   	cout << "-------- Listado de Consignados (" << tipos[auxTipo-1] << ") --------" <<endl;
   	cout << endl;

   	for(int i=0;i<cinco.getN();i++){
   		envio = cinco.get(i);

   		if(envio->getTipoEnvio() == auxTipo){
         	ListaConsignados & cons = envio->getListaConsignados();

      		for(int j=0;j<cons.getN();j++){
            	consignado = cons.get(j);

            	consignado->getDNI(auxDNI);
            	consignado->getNombre(auxNombre);

         		cout << "	" << (n+1) << ".- " << auxDNI << "   " << auxNombre << endl;
         		n++;
      		}
   		}
   	}

   	if(n == 0){
   		cout << endl;
      	cout << "\t* No hay CONSIGNADOS registrados en este tipo*" << endl;
   	}

   	cout << endl;
   	cout << "----------------------------------------------------" <<endl;
	getch();
}

// 8.6: Estadistica de Objetos
void estadisticaObjetos(){
   	int contador[4] = {0,0,0,0};
   	int auxTipo;

   	Envio *envio;

   	cout << endl;
  	cout << "--------- Estadisticas de Objetos --------" <<endl;
   	cout << endl;

   	for(int i=0;i<cinco.getN();i++){
   		envio = cinco.get(i);

      	auxTipo = envio->getTipoEnvio();

      	ListaObjetos & obje = envio->getListaObjetos();

      	for(int j=0;j<obje.getN();j++){
         	contador[auxTipo-1]++;
      	}
   	}

   	cout << "	Regular: " << contador[0] << endl;
   	cout << "	E-commerce: " << contador[1] << endl;
   	cout << "	Internacional: " << contador[2] << endl;
   	cout << "	Eventos: " << contador[3] << endl;

   	cout << endl;
   	cout << "------------------------------------------" <<endl;
	getch();
}

// 8.7: Simulacion de una Boleta
void simulacionBoleta(){
   	char *tipos[4] = {"Regular","E-commerce","Internacional","Eventos"};
   	char dni[MAXDNI];
   	char nombre[LIM];
   	char direccion[LIM];
   	char telefono[MAXFONE];
   	char correo[LIM];
   	char abreviatura[MAX];
   	char dignatario[LIM];
   	int numRemito;
   	int dia,mes,anio;
   	int tipoEnvio;
   	int hora,minuto,segundo;
   	float costo;
   	float igv;
   	float total;
   	float efectivo;
   	float vuelto;

   	Envio *envio;

   	numRemito = leeEntero("\n > Nro. de Remito[10,000-20,000] : ",10000,20000,"\t* Remito no valido");
   	envio = cinco.buscarEnvioPorRemito(numRemito);

   	if(envio != NULL){
      	envio->getFechaRegistro(dia,mes,anio);
   		envio->getDNI(dni);
      	envio->getNombre(nombre);
      	envio->getDireccion(direccion);
      	envio->getTelefono(telefono);
      	envio->getCorreo(correo);
      	tipoEnvio = envio->getTipoEnvio();

      	switch(tipoEnvio){
      		case 1: ((Regular *)envio)->getAbreviatura(abreviatura);
            		costo = ((Regular *)envio)->getCosto();
         		break;
         	case 2: ((Ecommerce *)envio)->getAbreviatura(abreviatura);
            		costo = ((Ecommerce *)envio)->getCosto();
         		break;
         	case 3: ((Internacional *)envio)->getAbreviatura(abreviatura);
            		costo = ((Internacional *)envio)->getCosto();
         		break;
         	case 4: ((Eventos *)envio)->getAbreviatura(abreviatura);
            		costo = ((Eventos *)envio)->getCosto();
         		break;
      	}

      	igv = costo*0.18;
      	total = costo + igv;
      	envio->getDignatario(dignatario);
      	envio->getTiempoRegistro(hora,minuto,segundo);

   		cout << endl;
      	cout << endl;
      	cout << endl;
      	cout << " =========================================================" << endl;
      	cout << endl;
      	cout << endl;

   		uno.mostrar();
   		cout << endl;
   		cout << "    		BOLETA DE VENTA ELECTRONICA" << endl;
      	cout << "    		 B011-" << numRemito << anio << "  " << dia << "/" << mes << "/" << anio << endl;
      	cout << endl;
      	cout << " DNI: " << dni << endl;
      	cout << " CLIENTE: " << nombre << endl;
      	cout << " DIRECCION: " << direccion << endl;
      	cout << " TELEFONO: " << telefono << endl;
      	cout << " CORREO: " << correo << endl;
      	cout << endl;
      	cout << " Para el seguimiento de sus envios en la pagina web o" << endl;
      	cout << " contact center, puede realizarlo mediante el Nro. REMITO:" << endl;
      	cout << " ---------------------------------------------------------" << endl;
      	cout << " NRO. REMITO  -  ANIO	DESCRIPCION" << endl;
      	cout << " ---------------------------------------------------------" << endl;
      	cout << "    " << numRemito << "     -  " << anio << "	" << tipos[tipoEnvio-1] << "(" << abreviatura << ")	  	" << costo << endl;
      	cout << " ---------------------------------------------------------" << endl;
      	cout << " OP. GRAVADA				S/.	" << costo << endl;
      	cout << " I.G.V.					S/.	" << igv << endl;
      	cout << endl;
      	cout << " IMPORTE TOTAL				S/.	" << total << endl;
      	cout << endl;
      	efectivo = leeReal(" EFECTIVO				S/.	",0.00,1000.0," ");
      	cout << endl;
      	vuelto = efectivo - total;
      	cout << " VUELTO					S/.	" << vuelto << endl;
      	cout << endl;
      	cout << endl;
      	cout << " DIG.: " << dignatario << "		 HORA: " << hora << ":" << minuto;
      	if(hora>=12){
      		cout << " PM" << endl;
      	}else{
      		cout << " AM" << endl;
      	}
      	cout << endl;
      	cout << "       Representacion impresa de la boleta de venta       " << endl;
      	cout << "     electronica, esta puede ser consultada en la web     " << endl;
      	cout << endl;
      	cout << "		Gracias por su preferencia" << endl;
      	cout << endl;
      	cout << endl;
      	cout << " =========================================================" << endl;
   	}else{
      	cout << endl;
   		cout << "\t* El envio solicitado no existe *" << endl;
   	}
   	getch();

}

// 8.8: Estado del Envio segun el Numero de Remito
void estadoSegunRemito(){
	int numRemito;
   	int diaRegistro,mesRegistro,anioRegistro;
   	int diaRuta,mesRuta,anioRuta;
   	int diaLlegada,mesLlegada,anioLlegada;
   	int diaDetalle,mesDetalle,anioDetalle;
   	int horaRegistro,minutoRegistro,segundoRegistro;
   	int horaRuta,minutoRuta,segundoRuta;
   	int horaLlegada,minutoLlegada,segundoLlegada;
   	int horaDetalle,minutoDetalle,segundoDetalle;
   	char auxNombre[MAX];
   	char auxDescripcion[LIM];

	Envio *envio;
   	Detalle *detalle;

   	cout << endl;
   	numRemito = leeEntero(" > Nro. de Remito[10,000-20,000] : ",10000,20000,"\t* Remito no valido");
   	envio = cinco.buscarEnvioPorRemito(numRemito);

   	if(envio != NULL){
      	envio->getFechaRegistro(diaRegistro,mesRegistro,anioRegistro);
      	envio->getFechaRuta(diaRuta,mesRuta,anioRuta);
      	envio->getFechaLlegada(diaLlegada,mesLlegada,anioLlegada);

      	envio->getTiempoRegistro(horaRegistro,minutoRegistro,segundoRegistro);
      	envio->getTiempoRuta(horaRuta,minutoRuta,segundoRuta);
      	envio->getTiempoLlegada(horaLlegada,minutoLlegada,segundoLlegada);

      	cout << endl;
      	cout << "--(REGISTRO)--	---(RUTA)---	--(LLEGADA)--" << endl;

      	cout << "  " << diaRegistro << "/" << mesRegistro << "/" << anioRegistro << "	";
      	if(horaRuta > 0){
      		cout << " " << diaRuta << "/" << mesRuta << "/" << anioRuta << "	";
      	}else{
      		cout << "    -/-/-	";
      	}
      	if(horaLlegada > 0){
      		cout << "  " << diaLlegada << "/" << mesLlegada << "/" << anioLlegada << endl;
      	}else{
			cout << "   -/-/-" << endl;;
      	}

      	cout << "   " << horaRegistro << ":" << minutoRegistro << ":" << segundoRegistro << "	";
      	if(horaRuta > 0){
      		cout << "  " << horaRuta << ":" << minutoRuta << ":" << segundoRuta << "	";
      	}else{
      		cout << "    -:-:-	";
      	}
      	if(horaLlegada > 0){
      		cout << "   " << horaLlegada << ":" << minutoLlegada << ":" << segundoLlegada << endl;
      	}else{
			cout << "   -:-:-" << endl;
      	}

      	cout << endl;
      	cout << " (+) DETALLES:" << endl;
      	cout << endl;

      	ListaDetalles & deta = envio->getListaDetalles();

      	for(int i=0;i<deta.getN();i++){
      		detalle = deta.get(i);

         	detalle->getNombre(auxNombre);
         	detalle->getDescripcion(auxDescripcion);
         	detalle->getFechaDetalle(diaDetalle,mesDetalle,anioDetalle);
         	detalle->getTiempoDetalle(horaDetalle,minutoDetalle,segundoDetalle);

			cout << " " << diaDetalle << "/" << mesDetalle << "/" << anioDetalle;
         	cout << "	" << auxNombre << ": " << endl;
         	cout << " " << horaDetalle << ":" << minutoDetalle << ":" << segundoDetalle;
         	cout << "	" << auxDescripcion << endl;
         	cout << endl;
      	}
   	}else{
      	cout << endl;
   		cout << " \t* El Nro. de REMITO solicitado no existe *" << endl;
   	}
   	getch();
}

// ***MENU :

// 1 -> Registrar Courier
void registrarCourier(){
   	system("cls");
   	cout << endl;

	uno.inicializar();
   	uno.leer();

   	cout << endl;
   	cout << "\t* COURIER registrada exitosamente *" << endl;
   	getch();
}

// 2 -> Registrar Tarifas
void registrarTarifas(){
   	Tarifa *tarifa = new Tarifa();
   	int flag,flag1;

   	system("cls");
  	cout << endl;

	tarifa->leer(flag,flag1);
   	if(flag == 0 && flag1 == 0){
   		dos.agregar(tarifa);

   		cout << endl;
   		cout << "\t* TARIFA registrada exitosamente *" << endl;
   	}
   	getch();
}

// 3 -> Registrar Destinos
void registrarDestinos(){
   	int tipo;

   	Destino *destino;

   	system("cls");
   	cout << endl;
   	cout << "[+---------- NUEVO DESTINO ----------+]" << endl;

   	tipo = leerTipoDestino();
  	destino = crearDestino(tipo);
   	destino->leer();
   	tres.agregar(destino);

   	cout << endl;
   	cout << "\t* DESTINO registrado exitosamente *" << endl;
   	getch();
}

// 4 -> Registrar Cliente

void registrarClientes(){
   	Cliente *cliente = new Cliente();

	system("cls");
   	cout << endl;
   	cout << "[--------------- Registrar Cliente ---------------]" << endl;
   	cout << endl;

   	cliente->setCodigo(cuatro.getN());
   	cliente->leer();
   	cuatro.agregar(cliente);

   	cout << endl;
   	cout << "\t* CLIENTE registrado exitosamente *" << endl;
   	getch();
}

// 5 -> Registrar Envios

void registrarEnvios(){
   	int tipo,flag = 0,flag1 = 0,dest;

	Envio *envio;

   	system("cls");
   	cout << endl;
   	cout << "[--------------- Registrar Envio ---------------]" << endl;

  	tipo = leerTipoEnvio();

   	if(tipo != 5){
   		if(tipo != 3){
   			dest = 1;

      		if(tipo == 2){
         		if(cuatro.getN() != 0){
      				flag1 = 1;
      			}
         	}
   		}else{
   			dest = 2;
   		}

   		for(int i=0;i<tres.getN();i++){
   			if(tres.get(i)->getTipoDestino() == dest){
      			flag = 1;
   			}
   		}

   		if(flag == 1){
			if(tipo != 2){
         		envio = crearEnvio(tipo);
   				envio->setNumeroRemito(cinco.getN());
   				envio->leer();
   				cinco.agregar(envio);
				cout << endl;
   				cout << "		* ENVIO registrado exitosamente *" << endl;
         	}else{
         		if(flag1 == 1){
            		envio = crearEnvio(tipo);
   					envio->setNumeroRemito(cinco.getN());
   					envio->leer();
   					cinco.agregar(envio);
					cout << endl;
   					cout << "		* ENVIO registrado exitosamente *" << endl;
      			}else{
            		cout << endl;
         			cout << " * No se han registrado clientes" << endl;
         		}
         	}
   		}else{
      		cout << endl;
         	cout << " * No se han registrado destinos del tipo requerido" << endl;
   		}
   	}else{
   		cout << endl;
      	cout << "	* ENVIO cancelado * " << endl;
   	}
   	getch();
}

// 6 -> Registrar Detalles

void registrarDetalles(){
   	int auxRemito;

   	Envio *envio;
   	Detalle *detalle = new Detalle();

   	system("cls");
   	cout << endl;
   	cout << "[-------- Registrar Detalle --------]" << endl;
   	cout << endl;

   	cout << " > Nro. Remito[10,000-20,000]: "; cin >> auxRemito;

   	envio = cinco.buscarEnvioPorRemito(auxRemito);
   	ListaDetalles & deta = envio->getListaDetalles();

   	cout << endl;

   	if(envio != NULL ){
      	detalle->leer();
      	deta.agregar(detalle);

      	cout << endl;
      	cout << "\t* El DETALLE se registro exitosamente *" << endl;
   	}else{
      	cout << endl;
   		cout << "\t* No se encontro envio solicitado *" << endl;
   	}
   	getch();
}

// 7 -> Actualizacion de Estado

int leerEstado(){
	char *estados[3]={"Ruta","Llegada","Cancelar"};
   	int estado;

   	for(int i=0;i<3;i++){
   		cout << "	(" << (i+1) << ") " << estados[i] << endl;
   	}

	estado = leeEntero("		Opcion : ",1,3,"\t* Opcion no valida");

   	return estado;
}

void actualizacionEstado(){
   	int auxRemito;
   	int nuevoEstado;
   	int op;

   	Envio *envio;

   	system("cls");
   	cout << endl;
   	cout << "[-------- Actualizar Estado --------]" << endl;
   	cout << endl;

   	auxRemito = leeEntero(" > Nro. de remito[10,000-20,000] : ",10000,20000,"\t* Remito no valido");
   	envio = cinco.buscarEnvioPorRemito(auxRemito);
   	cout << endl;

   	if(envio != NULL){
      	op = envio->getEstado() + 1;

      	switch(op){
   			case 1:
      			cout << "	(1) Ruta"<< endl;
      			cout << "	(2) Retornar"<< endl;
         		nuevoEstado = leeEntero(" Opcion : ",1,2,"\t* Opcion no valida");

	         	if(nuevoEstado == 1){
	         		envio->setFechaRuta();
	            	envio->setTiempoRuta();
	            	envio->setEstado(nuevoEstado);
	
	               	cout << endl;
	      			cout << "\t* El estado del envio ha sido actualizado " << endl;
	         	}
         	break;

			case 2:
      			cout << "	(1) Llegada"<< endl;
      			cout << "	(2) Retornar"<< endl;
         		nuevoEstado = leeEntero(" Opcion : ",1,2,"\t* Opcion no valida");

         		if(nuevoEstado == 1){
         			envio->setFechaLlegada();
            		envio->setTiempoLlegada();

            		envio->setEstado(nuevoEstado + 1);

               		cout << endl;
      				cout << "\t* El estado del envio ha sido actualizado" << endl;
         		}
            break;

      		case 3:
         		cout << "\t* No es posible la actualizacion, el envio ha llegado al destino";
      		break;
      	}
   	}else{
      	cout << endl;
   		cout << "\t* El envio solicitado no existe *" << endl;
   	}
   	getch();
}

// 8 -> Presentar Reportes

void presentarReportes(){
  	int rep;

	do{
      	system("cls");
  		cout<<"[+------------- REPORTES -------------+]"<<endl;

  		rep = leerReporte();

   		switch(rep){
   			case 1: datosRegistrados(); break;
         	case 2: listaEnvios(); break;
         	case 3: listaDestinosSegunTipo(); break;
         	case 4: listaObjetosSegunEnvio(); break;
         	case 5: listaConsignadosSegunEnvio(); break;
         	case 6: estadisticaObjetos(); break;
      		case 7: simulacionBoleta(); break;
      		case 8: estadoSegunRemito(); break;
         	case 9: break;
   		}
  	}while(rep < 9);
}


// + MAIN +
int main(){
  	int op;

	do{
  		system("cls");
  		cout<<"[+------------> { * MENU * } <------------+]"<<endl;

  		op = leerOpcion();

   		switch(op){
         	case 1: 
			 	registrarCourier();
         		flag = 1;
         	break;
         	
         	case 2: 
			 	if(flag == 1){
         			registrarTarifas();
                  	flag1 = 1;
                }else{
                 	cout << "\t* Courier no registrada" << endl;
                  	getch();
                }
         	break;
         	
         	case 3: 
			 	if(flag1 == 1){
         			registrarDestinos();
                  	flag2 = 1;
         		}else{
                 	cout << "\t* Tarifas no registrada" << endl;
                  	getch();
                }
         	break;
         	
      		case 4: 
			  	if(flag == 1){
         			registrarClientes();
            	}else{
                 	cout << "\t* Courier no registrada" << endl;
                  	getch();
                }
         	break;
         	
         	case 5: 
			 	if(flag2 == 1){
         			registrarEnvios();
                 	flag3 = 1;
            	}else{
                 	cout << "\t* Departamentos no registrada" << endl;
                  	getch();
                }
         	break;
         	
         	case 6: 
			 	if(flag3 == 1){
         			registrarDetalles();
            	}else{
                 	cout << "\t* No hay Envios registrados" << endl;
                  	getch();
                }
         	break;
         	
         	case 7: 
			 	if(flag3 == 1){
         			actualizacionEstado();
            	}else{
                 	cout << "\t* No hay Envios registrados" << endl;
                  	getch();
                }
         	break;
         	
      		case 8: 
			  	if(flag == 1 && flag3 == 1){
         			presentarReportes();
            	}else{
                 	cout << "\t* Faltan datos" << endl;
                  	getch();
                }
         	break;
   		}
  	}while(op < 9);
}
