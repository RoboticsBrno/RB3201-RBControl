BOARDS = $(wildcard [!_autosave]*.kicad_pcb)

.PHONY: manu clean

manu: $(BOARDS:.kicad_pcb=-gerber.zip)

clean:
	rm -rf $(BOARDS:.kicad_pcb=-gerber)
	rm -rf $(BOARDS:.kicad_pcb=-gerber.zip)

%-gerber: %.kicad_pcb
	./export_gerber.py $< $@

%-gerber.zip: %-gerber
	zip -j $@ `find $<`

