# LAB3-Memoria

## (a) Nombres completos de los integrantes, correos y números de documento.

### Santiago Jiménez Escobar - santiago.jimeneze@udea.edu.co - C.C 1036959331
### Emiro Moreno Soto - emiro.morenos@udea.edu.co - C.C 1001547311

## (b) Documentación de todas las funciones desarrolladas en el código.

### 1.3 Actividad: Exploración de /proc/[pid]/maps
1. **Identifique en la salida de /proc/maps las regiones text, heap y stack. ¿Qué permisos
(r/w/x/p) tiene cada una? ¿Por qué difieren?**

    La región **text** se puede encontrar al comparar Dir. codigo (main) : 0x55a3176da209 que es el resultado de la ejecución del código, con cada una de las líneas que salen al ejecutar ``cat /proc/$(pgrep mem_map)/maps`` en este resultado encontramos la línea 55a3176da000-55a3176db000 r-xp 00001000 00:45 281474976977211            /mnt/d/VSC/LAB3-memoria/codigo/mem_map. Al realizar la comparación, se encuentra que la dirección 0x5d98cfb49209 esta dentro del rango 55a3176da000-55a3176db000, adicional tiene los permisos de lectura, ejecución y private (r-xp), de los cuales se destaca el de ejecución, necesario para que el procesador pueda ejecutar el codigo y no tiene el de escritura, ya que por seguridad no debería poder ejecutarse y modificarse al mismo tiempo.

    La región **Heap** de manera similar se puede identificar de manera similar al comparar Dir. heap_var : 0x55a31c5f62a0 con el resultado de ejecutar ``cat /proc/$(pgrep mem_map)/maps``. En este caso, la dirección 0x55a31c5f62a0 está dentro del rango 55a31c5f6000-55a31c617000. En cuanto a los permisos que tiene, son de lectura, escritura y private (rw-p). En cuanto a la comparación del Heap y Stack tienen el mismo tipo de permisos, y debe ser de esta manera para poder leer y escribir variables, punteros o retornos de función en tiempo de ejecución. En cuanto a la región de text se nota claramente que no cuentan con el permiso de ejecución, (x) ya que por seguridad no debería un programa poder escribir y ejecutar al mismo tiempo.

    De manera similar, la región **Stack** se logra encontrar a partir de comparar Dir. local_var : 0x7ffe12f7225c con el resultado de ejecutar ``cat /proc/$(pgrep mem_map)/maps``, en cuyo resultado encontramos el rango de direcciones 7ffe12f52000-7ffe12f74000, en cuyo rango cabe perfectamente el resultado de Dir. local_var, otro dato a tener en cuenta es que el rango de direcciones se nos está dando en la parte superior de la memoria; en cuanto a los permisos que tiene, son de lectura, escritura y private (rw-p). En cuanto a la comparación del Heap y Stack tienen el mismo tipo de permisos, y debe ser de esta manera para poder leer y escribir variables, punteros o retornos de función en tiempo de ejecución; así mismo, la única diferencia con la región text es el permiso de private (x).


2. Compare las direcciones impresas con los rangos de /proc/maps. ¿A qué región pertenece
cada variable?

    Al realizar la ejecucion del codigo se obtiene el siguiente resultado:
    PID del proceso : 5716
    Dir. codigo (main) : 0x55a3176da209
    Dir. global_var : 0x55a3176dd010
    Dir. local_var : 0x7ffe12f7225c
    Dir. heap_var : 0x55a31c5f62a0

    Al comparar cada direccion se puede obtener los siguientes rangos y al frente se coloca la direccion que pertenece a cada rango.
    - 55a3176d9000-55a3176da000 
    - 55a3176da000-55a3176db000  -> Dir. codigo (main) : 0x55a3176da209 (Region text)
    - 55a3176db000-55a3176dc000
    - 55a3176dc000-55a3176dd000
    - 55a3176dd000-55a3176de000  -> Dir. global_var : 0x55a3176dd010 (Region Data)
    - 55a31c5f6000-55a31c617000  -> Dir. heap_var : 0x55a31c5f62a0 (Region heap)
    - 7673a9c00000-7673a9c28000 
    - 7673a9c28000-7673a9db0000 
    - 7673a9db0000-7673a9dff000 
    - 7673a9dff000-7673a9e03000 
    - 7673a9e03000-7673a9e05000 
    - 7673a9e05000-7673a9e12000 
    - 7673a9eed000-7673a9ef0000  
    - 7673a9ef5000-7673a9ef7000 
    - 7673a9ef7000-7673a9ef8000 
    - 7673a9ef8000-7673a9f23000 
    - 7673a9f23000-7673a9f2d000   
    - 7673a9f2d000-7673a9f2f000 
    - 7673a9f2f000-7673a9f31000 
    - 7ffe12f52000-7ffe12f74000  -> Dir. local_var : 0x7ffe12f7225c (Region stack)
    - 7ffe12fef000-7ffe12ff3000 
    - 7ffe12ff3000-7ffe12ff5000
3. ¿Qué otras regiones aparecen en el mapa (libc, [vdso], [vsyscall])? ¿Que función
cumple cada una?

    Otra región que aparece es (data) y es la región donde se almacena global_var.

    libc.so.6: Es la librería estándar de C en la cual se encuentran la mayoría de    funciones, como son: ``printf()``, ``malloc()``, ``scanf()``

    vdso (Virtual Dynamic Shared Object): Es una biblioteca del kernel la cual ayuda a ejecutar ciertas tareas básicas que, debido a su simplicidad, no es necesario realizar una llamada al sistema, sino más bien realizarlas en tiempo de ejecución.

    vvar: Contiene los datos que el vdso necesita para trabajar.

    Cargador Dinámico (Dynamic Linker/Loader)ld-linux: Se encarga de conectar funciones básicas como ``printf()``, ``malloc()``, ``scanf()`` con la ejecución de las demás funciones de mi código; adicionalmente, es como el iniciador del programa, ayudando a que todo funcione de manera unificada.

4. ¿Son las direcciones virtuales iguales a las fisicas? Explique apoyandose en el concepto de address space del OSTEP.

    Según el libro de (Operating Systems: Three Easy Pieces) el (address space) o espacio de direccionamiento se refiere a la abstracción que realiza el sistema operativo en cuanto al espacio de memoria que ocupa un proceso. En este caso, la abstracción consiste en hacerle creer que tiene toda la memoria RAM a su disposición, que empieza en 0 y llega hasta un máximo (por ejemplo, $2^{n}-1$). En cuanto a una dirección virtual, se refiere a la dirección de memoria que se le asigna al proceso, sin embargo, internamente, esta dirección no corresponde a la dirección física, la cual es la verdadera dentro de toda la ejecución del programa. Es por esta abstracción que se puede decir que una dirección virtual no es lo mismo que una dirección física, ya que su valor cambia constantemente.


## (c) Problemas presentados durante el desarrollo de la práctica y sus soluciones.


## (d) Pruebas realizadas a los programas que verificaron su funcionalidad.

En la siguiente imagen se observa la ejecución del programa base y su resultado
![wish](capturas/mem_map2.PNG)

Luego el resultado de realizar abrir una segunda terminal y leer el mapa de memoria del proceso mediante el comando cat /proc/$(pgrep mem_map)/maps
![wish](capturas/mem_map1.PNG)


## (e) Un enlace a un video de 10 minutos donde se sustente el desarrollo.

[Haz clic aquí para ver el video](https://youtu.be/kZarcqfpLcY)


## (f) Manifiesto de transparencia: En que puntos se apoyaron de la IA generativa.
