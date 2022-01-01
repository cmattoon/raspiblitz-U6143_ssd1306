.DEFAULT_GOAL := help

.PHONY: help
help: ## display this message
help:
	@grep -E '^[0-9a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

.PHONY: enable-i2c
enable-i2c: ## Enable I2C 
enable-i2c:
	sudo raspi-config nonint do_i2c 1

.PHONY: build
build: ## build binary
build:
	cd src && make

.PHONY: install
install: ## install binary and systemd service - NEEDS SUDO
install: build enable-i2c
	cp src/display /usr/local/bin/lcd-monitor && chmod +x /usr/local/bin/lcd-monitor
	cp files/lcd-monitor.service /etc/systemd/system/lcd-monitor.service
	systemctl daemon-reload
	systemctl enable lcd-monitor
	systemctl restart lcd-monitor
