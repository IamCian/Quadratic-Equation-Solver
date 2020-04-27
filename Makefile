quadeq:
	@gcc quadeq.c -o quadeq

.PHONY: install uninstall

install:
	@cp quadeq /usr/local/bin

uninstall:
	@rm /usr/local/bin/quadeq
