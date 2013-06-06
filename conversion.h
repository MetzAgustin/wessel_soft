/*
 * conversion.h
 *
 *  Created on: 22/04/2013
 *      Author: utnso
 */

#ifndef CONVERSION_H_
#define CONVERSION_H_

#include <math.h>
#include "definiciones.h"

complejoPol convertBinToPolar (complejoBin);
complejoBin convertPolarToBin (complejoPol);
complejoExp convertTrigToExp (complejoTrig);
complejoTrig convertExpToTrig (complejoExp);

int determinarCuadrante (complejoBin);

double modulo (complejoBin);


#endif /* CONVERSION_H_ */
