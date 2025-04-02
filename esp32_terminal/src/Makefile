# Nombre del contenedor e imagen
DOCKER_IMAGE=espressif/idf:latest

# Detectar puerto serie (ajusta si estás en Windows)
PORT?=/dev/ttyUSB0

# Ruta del proyecto dentro del contenedor
WORKDIR=/project

# Comando base para ejecutar Docker
DOCKER_RUN=docker run --rm -v $(PWD):$(WORKDIR) -w $(WORKDIR) $(DOCKER_IMAGE)

# Comando con acceso a dispositivo serie (solo para flash y monitor)
DOCKER_RUN_SERIAL=docker run --rm -v $(PWD):$(WORKDIR) --device=$(PORT) -w $(WORKDIR) -it $(DOCKER_IMAGE)

build:
	$(DOCKER_RUN) idf.py build

menuconfig:
	$(DOCKER_RUN) idf.py menuconfig

flash:
	$(DOCKER_RUN_SERIAL) idf.py -p $(PORT) flash

monitor:
	$(DOCKER_RUN_SERIAL) idf.py -p $(PORT) monitor

flash-monitor:
	$(DOCKER_RUN_SERIAL) idf.py -p $(PORT) flash monitor
