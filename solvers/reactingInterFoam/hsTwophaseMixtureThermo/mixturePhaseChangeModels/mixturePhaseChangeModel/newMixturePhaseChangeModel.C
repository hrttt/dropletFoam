/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "mixturePhaseChangeModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

Foam::autoPtr<Foam::mixturePhaseChangeModel>
Foam::mixturePhaseChangeModel::New
(
    const word name,
    const fvMesh& mesh,
    const phase& alphaL,
    const phase& alphaV,
    const PtrList<gasThermoPhysics>& speciesData,
    dictionary phaseChangeDict
)
{
    word mixturePhaseChangeModelTypeName
    (
        phaseChangeDict.lookup("phaseChangeModel")
    );

    Info<< "Selecting phase change model "
        << mixturePhaseChangeModelTypeName << endl;

    componentsConstructorTable::iterator cstrIter =
        componentsConstructorTablePtr_
            ->find(mixturePhaseChangeModelTypeName);

    if (cstrIter == componentsConstructorTablePtr_->end())
    {
        FatalErrorIn
        (
            "mixturePhaseChangeModel::New"
        )   << "Unknown mixturePhaseChangeModel type "
            << mixturePhaseChangeModelTypeName << endl << endl
            << "Valid  mixturePhaseChangeModel are : " << endl
            << componentsConstructorTablePtr_->sortedToc()
            << exit(FatalError);
    }

    return autoPtr<mixturePhaseChangeModel>
    (
        cstrIter()
        (
            name,
            mesh,
            alphaL,
            alphaV,
            speciesData,
            phaseChangeDict
        )
    );
}


// ************************************************************************* //
