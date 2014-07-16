
Chemistry Database
===========================
 
This program builds liquid/gas chemistry input files from a selection of 
reaction sets. Details about the individual sets are included below. To build a
multiphase chemistry set in a python script, use:

    import chemBuilder
    reaction_set = chemBuilder.build_set('GasChem2','LiquidChem2')
    reaction_set.write_file('chem.inp')

Gas Reaction Sets
=========================
The following reaction sets are for gaseous reaction with MMH and various 
oxidizers

## GasChem0

| Species | Reactions | Reference    |
| ------- | --------- | ------------ |
| 2       | 1         | N/A          |

    
Empty gas mechanism with just N and N2 species and HCON elements as basis 
for non-reacting cases. The N2<=>N decomposition reaction is included since
the chemkinToFoam converter crashes with 0 reactions.
    
## GasChem1

| Species | Reactions | Reference    |
| ------- | --------- | ------------ |
| 80      | 512       | W. Anderson, M. McQuaid, M. Nusca, A. Koltar, "A detailed,
               finite-rate, chemical kinetics mechanism for monomethylhydrazine
               red fuming nitric acid systems," Army Research Laboratory,
               ARL-TR-5088, February 2010|

This is the original ARL mechanism, but without the 'NAMMH' reaction.

## GasChem2
    Species:   25
    Reactions: 98
    Reference: N. Labbe, Y. Kim, P. Westmoreland, "Computational mechanism
               development for hypergolic propellant systems: MMH and DMAZ,"
               Proceedings of the 2010 AIChE Annual Meeting, Salt Lake City, UT
    
    This is Labbe's reduced version of the ARL mechanism, internally referred to
    as RChem1

## GasChem3
    Species:   29
    Reactions: 120
    Reference: Labbe/Westmoreland internal communications, MURI Task 3.2
    
    This is Labbe's reduced version of the ARL mechanism, internally referred to
    as RChem2

## GasChem4
    Species:   41
    Reactions: X
    Reference: N. Labbe, "Determining detailed reaction kinetics for nitrogen
               and oxygen containing fuels," Ph.D. Thesis, University of
               Massachusetts Amherst, February 2013
    
    This is Labbe's new mechanism, internally referred to as RChem3

## GasChem5
    Species:   41
    Reactions: X-4
    Reference: Labbe/Westmoreland
    
    This is Labbe's new mechanism, internally referred to as RChem3S, which is
    the same as GasChem4 but with 4 stiff reactions removed

## GasChem6
    Species:   35
    Reactions: 49
    Reference: ARL/McQuaid
    
    This is a reduced version of the original ARL mechanism provided by McQuaid.
    The only modification made internally is the removal of the NAMMH reaction.

   
    
Liquid reaction sets
================================================================================
The following liquid reaction sets are predominantly to enable reaction pathways
between MMH and nitric acid in liquid phase.

    
## LiquidChem1
    Species:    9
    Reactions:  1
    Reference:  TBD
    
    This is a global one-step reaction between MMH and nitric acid producing
    heat and intermediates based on some observations by Thynell (ref). It also
    includes liquid NO2 so it can evaporate and work with RFNA, but there is no
    reaction between liquid MMH and liquid NO2
    
## LiquidChem2
    Species:    11
    Reactions:  2
    Reference:  TBD
    
    This includes the global 1-step reaction from LiquidChem2 and the forward
    aerosol reaction.


