# LAB3-Memoria

## (a) Nombres completos de los integrantes, correos y números de documento.

### Santiago Jiménez Escobar - santiago.jimeneze@udea.edu.co - C.C 1036959331
### Emiro Moreno Soto - emiro.morenos@udea.edu.co - C.C 1001547311

## (b) Documentación de todas las funciones desarrolladas en el código.

### 1.3 Actividad: Exploración de /proc/[pid]/maps
1. **Identifique en la salida de /proc/maps las regiones text, heap y stack. ¿Qué permisos
(r/w/x/p) tiene cada una? ¿Por qué difieren?**

    La región **text** se puede encontrar al comparar Dir. Código (main) : 0x5d98cfb49209 que es el resultado de la ejecución del código, con cada una de las líneas que salen al ejecutar ``cat /proc/$(pgrep mem_map)/maps`` en este resultado encontramos la línea 5d98cfb49000-5d98cfb4a000 r-xp 00001000 00:45 281474976977211 /mnt/d/VSC/LAB3-memoria/codigo/mem_map. Al realizar la comparación, se encuentra que la dirección 0x5d98cfb49209 esta dentro del rango 5d98cfb49000-5d98cfb4a000, adicional tiene los permisos de lectura, ejecución y private (r-xp), de los cuales se destaca el de ejecución, necesario para que el procesador pueda ejecutar el codigo y no tiene el de escritura, ya que por seguridad no debería poder ejecutarse y modificarse al mismo tiempo.

![wish](capturas/mem_map1.PNG)

### **Implementación de shell basico, Path, Built-in commands**
- Funcion  ``print_error()``: Esta función es utilizada para los casos en los cuales el aplicativo genere algún error en ejecución, por lo cual se centraliza con esta función la cual incluye subfunciones como ``write()`` para poder imprimir por la salida de errores el mensaje y ``strlen()`` la cual ayuda a contar la cantidad de caracteres o bytes que tiene el mensaje a mostrar.

## (c) Problemas presentados durante el desarrollo de la práctica y sus soluciones.


## (d) Pruebas realizadas a los programas que verificaron su funcionalidad.

En la siguiente imagen se observa la ejecución del shell ingresando un archivo en el cual se encuentran los comandos a ejecutar (modo batch)
![wish](capturas/wish.PNG)


## (e) Un enlace a un video de 10 minutos donde se sustente el desarrollo.

[Haz clic aquí para ver el video](https://youtu.be/kZarcqfpLcY)


## (f) Manifiesto de transparencia: En que puntos se apoyaron de la IA generativa.
