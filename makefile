CFLAGS:= -pthread
GCC:= g++
RM:= rm

.PHONY: $(TARGET)
.PHONY: clean
.PHONY: run
.PHONY: again


#LAS RUTAS PARA LOS ARCHIVOS .c, .o y .h (en ese orden)
SRCPATH = ./src/
OBJPATH = ./obj/

#NOMBRE DEL EJECUTABLE
TARGET := diagnostico


#ARCHIVOS A COMPILAR
OBJ1:=  main.o \

OBJ:= $(patsubst %,$(OBJPATH)%, $(OBJ1))


#PRIMERO SE COMPILAN LOS ARCHIVOS .c
$(OBJPATH)%.o: $(SRCPATH)%.cpp
	@echo [GCC] $<
	@$(GCC) $(CFLAGS) -o $@ -c $< $(INCLUDEPATH) $(LFLAGS)

#LINKEAMOS TODO
$(TARGET): $(OBJ)
	@echo [INFO] Creando ejecutable binario [$(TARGET)]
	@$(GCC) -o $@ $^ $(LFLAGS)

# LIMPIAR TODOS LOS ARCHIVOS .o Y EL EJECUTABLE
clean:   
	@echo "[Limpiando...]"
	@$(RM) -rfv $(OBJPATH)*
	@$(RM) -rfv $(TARGET)

run: $(TARGET)
	@echo "[Ejecutando...]"
	@./$(TARGET)

#RECOMPILAR
again: clean run
