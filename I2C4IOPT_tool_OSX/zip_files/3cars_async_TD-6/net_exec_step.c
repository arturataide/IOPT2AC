/* Net N_3carros_TD - IOPT */
/* Automatic code generated by IOPT2C XSLT transformation. */


#include <stdlib.h>
#include <string.h>
#include "net_types.h"


static N_3carros_TD_TransitionFiring tfired;
    

void N_3carros_TD_ExecutionStep(
     N_3carros_TD_NetMarking *prev_marking,
     N_3carros_TD_InputSignals *inputs,
     N_3carros_TD_InputSignals *prev_in,
     N_3carros_TD_PlaceOutputSignals *place_out,
     N_3carros_TD_EventOutputSignals *ev_out )
{
    N_3carros_TD_NetMarking add_marking;
    N_3carros_TD_NetMarking avail_marking = *prev_marking;
    N_3carros_TD_InputSignalEvents input_events;
    N_3carros_TD_OutputSignalEvents output_events;

    memset( &output_events, 0, sizeof(output_events) );
    memset( &tfired, 0, sizeof(tfired) );

    createEmpty_N_3carros_TD_NetMarking( &add_marking );
    N_3carros_TD_GetInputSignals( inputs, &input_events );
    N_3carros_TD_GenerateInputSignalEvents( prev_in, inputs, &input_events );
    *prev_in = *inputs;

    /* Transition BACK_copy6 */
    if( t_45_enabled( prev_marking, &avail_marking ) &&
        t_45_events( &input_events ) &&
        t_45_guards( prev_marking, inputs, place_out, ev_out ) ) {
        tfired.t_45 = 1;
        t_45_remove_marks( &avail_marking );
        t_45_add_marks( &add_marking );
        t_45_generate_output_events( &output_events );
    }

    /* Transition B6 */
    if( t_46_enabled( prev_marking, &avail_marking ) &&
        t_46_events( &input_events ) &&
        t_46_guards( prev_marking, inputs, place_out, ev_out ) ) {
        tfired.t_46 = 1;
        t_46_remove_marks( &avail_marking );
        t_46_add_marks( &add_marking );
        t_46_generate_output_events( &output_events );
    }

    /* Transition GO_copy6 */
    if( t_47_enabled( prev_marking, &avail_marking ) &&
        t_47_events( &input_events ) &&
        t_47_guards( prev_marking, inputs, place_out, ev_out ) ) {
        tfired.t_47 = 1;
        t_47_remove_marks( &avail_marking );
        t_47_add_marks( &add_marking );
        t_47_generate_output_events( &output_events );
    }

    /* Transition A6 */
    if( t_49_enabled( prev_marking, &avail_marking ) &&
        t_49_events( &input_events ) &&
        t_49_guards( prev_marking, inputs, place_out, ev_out ) ) {
        tfired.t_49 = 1;
        t_49_remove_marks( &avail_marking );
        t_49_add_marks( &add_marking );
        t_49_generate_output_events( &output_events );
    }

    add_N_3carros_TD_NetMarkings( &avail_marking, &add_marking );

    N_3carros_TD_GenerateTransitionActionOutputSignals( &tfired, &avail_marking, ev_out );
    N_3carros_TD_GeneratePlaceOutputSignals( &avail_marking, inputs, place_out, ev_out );
    N_3carros_TD_GenerateEventOutputSignals( &output_events, ev_out );
    N_3carros_TD_PutOutputSignals( place_out, ev_out, &output_events );
    *prev_marking = avail_marking;
}

N_3carros_TD_TransitionFiring* get_N_3carros_TD_TransitionFiring()
{
    return &tfired;
}

