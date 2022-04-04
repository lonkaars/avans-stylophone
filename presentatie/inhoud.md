# presentatie inhoud

## introductie doel / onderwerp

tijdens deze presentatie:
- algemene werking van de stylofoon uitleggen
- geïmplementeerde uitbereidingen

## functies / specificaties

- inplaats van shiftregister leest Arduino het toetsenbord uit
- werkt op een standaard usb 2.0 poort (2.5W max)
- mixer tussen de arduino en 555 synth
- extra knoppen om het arduino geluid aan te passen

## snelle doorloop werking en uitleg uitbereidingen

- voeding komt binnen via losse usb poort links boven op de printplaat
- gaat naar de globale aan/uit schakelaar bovenaan
- een 555 timer circuit maakt een blokgolf, en deze gaat de mixer in
- de arduino maakt een andere golfvorm, en gaat ook de mixer in
- mixer uitgang gaat in lm386 versterker
- versterker uitgang gaat naar koptelefoon uitgang en m.b.v. diode en
	condensator naar de peak detector van de vu-display
- de arduino krijgt nog 3 analoge inputdraaiknoppen, dit zijn gewoon 3
	potmeters die als spanningsdeler werken

## erkenning tekortkomingen / gepoogde oplossingen

- volumeknop stuk (waarom?)
- constante middentoon
- 

## leermomenten

## korte samenvatting urenrapportage als uitsmijter ofzo
## demo


