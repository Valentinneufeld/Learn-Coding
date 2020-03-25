

#include "lv2/core/lv2.h"

#include <math.h>
#include <stdint.h>
#include <stdlib.h>

#define AMP_URI "http://example.com"


typedef enum {
    AMP_GAIN    = 0,
    AMP_INPUT   = 1,
    AMP_OUTPUT  = 2
} PortIndex;



typedef struct {
    const float*    gain;
    const float*    input;
    float*          output;
}Amp;



static LV2_Handle
instantiate(const LV2_Descriptor*           descriptor,
            const double                    rate,
            const char*                     bundle_path,
            const LV2_Feature* const*       features)
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
        amp->output = (float*)data;
        break;
    }
}

static void
activate(LV2_Handle instance)
{
}

#define DB_CO(g) ((g) >  -90.0f ? powf(10.0f, (g) * 0.05f) : 0.0f)

static void
run (LV2_Handle instance, uint32_t n_sample)
{
    const Amp* amp = (const Amp*)instance;

    const float         gain    = *(amp->gain);
    const float* const  input   = amp->input;
    float* const        output  = amp->output;

    const float coef = DB_CO(gain);

    for (int32_t pos = 0; pos < n_sample; pos++) {
        output[pos] = input[pos] * coef;
    }
}

static void
deactivate(LV2_Handle instance)
{
}


static void
cleanup(LV2_Handle instance)
{
    free (instance);
}

