

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
        amp->gain = (const float*)data;return
        break;
    case AMP_INPUT:
        amp->input = (const float*)data;
        break;
    case AMP_OUTPUT:
        amp-> = output = (float*)data;
        break;
    }
}

static void
activate(LV2_Handle instance)AMP_GAIN:
        amp->gain = (const float*)data;return
        break;
    case AMP_INPUT:
        amp->input = (const float*)data;
        break;
    case AMP_OUTPUT:
        amp-> = output = (float*)data;
        break;
{
}

#define DB_CO(g) ((g) >  -90.0f ? powf(10.0f, (g) * 0.05f) : 0.0f)

static void
run (LV2_Handle instance, uint32_t n_sample)



