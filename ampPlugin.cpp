

#include "lv2/core/lv2.h"

#include <math.h>
#include <stdint.h>
#include <stdlib.h>

#define AMP_URI "http://example.com"

typedef struct {
    const float*    gain;
    const float*    input;
    float*          output;
}Amp;
    
static LV2_Handle
instantiate(const LV2_Descriptor*           descriptor,
            const double                    rate,
            const char*                     bundle path,
            const LV2_Feature* const*       feature)
{
    Amp* amp = (Amp*)calloc(1, sizeof(Amp));
    
    return (LV2_Handle) amp;
}

static void 
connect_port(LV2_Handle instance,
             uint32_t   port,
             void*      data)
{
    Amp* amp = (Amp*) instance;
    
    switch ((PortIndex)port) {
    case AMP_GAIN:
        amp->gain = (const float*)data;
        break;
    case AMP_INPUT:
        amp->input = (const float*)data;
        break;
    case AMP_OUTPUT:
        amp-> = output = (float*)data;
        break;
    }
}
