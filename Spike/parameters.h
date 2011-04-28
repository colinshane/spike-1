/*
 *  parameters.h
 *  Spike
 *
 *  Created by Ben Evans on 18/08/2008.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _PARAMETERS_H
#define _PARAMETERS_H

#include <stdbool.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

typedef int tstep; // Signed to allow spikeTimes[0] = -BIG //long long

typedef unsigned char uchar;

struct SIMULATION{
	bool Xgrid;
	tstep tally;
	tstep ptTS;
	tstep trainTS;
	tstep testTS;
	tstep totTS;
} SIM;

typedef struct DIMENSIONS {
	int nRows;
	int nCols;
	int nFilt;
} DIM;

//extern SIMULATION SIM;

typedef enum {
	Off,
	Uniform,
	Gaussian
} NOISE;

typedef enum {
	MinD,
	ConstD,
	UniformD,
	GaussD,
	SOM
} DELAY;

typedef enum {
	None,
	MaintainLength,
	MaintainSum
} NORMALISATION;

/********************** Main Network Parmeters *************************/
// Update read_parameters and defaults.m when a new parameter is added
typedef struct {
	// Simulation
	float DT;
	int loops;
	bool train;// = true;
	bool pretrain;// = true;
	bool trainPause;
	int noise;
	float noiseScale;
	float SigmaE;
	float SigmaI;
	NORMALISATION normalise;
	int nRecordsPL;// = 0;
	int nRecords;
	int * vRecords;
	float TotalTime;
	int TotalMS;
	int TotalTS;
	int TSperMS;
	int spkBuffer;
	//int inpSpkBuff;
	bool printConnections;
	bool saveInputSpikes;
	bool probConnect;
	
	// Stimuli
	char * imgDir;
	char * imgList;
	bool randStimOrder;// = true;
	bool randTransOrder;
	bool randTransDirection;
	bool interleaveTrans;
	bool localRep;// = true;
	float current;// = 1.25e-9;
	float currentSpread;
	int nStimuli;
	int nTransPS;
	bool newTestSet;
	int M; // Degree of training i.e. train with M of the NCK
	int K; // Number of stimuli presented simultaneously
	int nTestStimuli;
	int nTestTransPS;
	float transP_Train;
	float transP_Test;
	int shift;
	int nFiringNeurons;
	float a; // Sparseness of stimuli
	bool useFilteredImages;
	bool gabor;
	int nScales;
	int * vScales;
	int nOrients;
	int * vOrients;
	int nPhases;
	int * vPhases;
	int sInputs;
	int nRows;
	int nCols;
	
	// Network
	int nLayers;// = 2;
	int nWLayers;
	bool inputInhib;
	int nExcit;// = 120;
	int * vExcit;
	int LvExcit;
	int nSynEfE;
	float * pCnxEfE;
	int LpEfE;
	int nSynElE;
	float * pCnxElE;
	int LpElE;
	int nSynIE;
	float * pCnxIE;
	int LpIE;
	int nInhib;// = 40;
	float rInhib;
	int * vInhib;
	int LvInhib;
	int nSynEI;
	float * pCnxEI;
	int LpEI;
	int nSynII;
	float * pCnxII;
	int LpII;
	DELAY axonDelay;
	float d_const;
	float d_min;
	float d_max;
	float d_mean;
	float d_sd;
	float spatialScale;
	float condSpeed;
	float maxDelay;
	bool SOM;
	bool SOMinput;
	float SOMsigE;
	float SOMsigI;
	float SOMclip;
	//float SOMstrE;
	//float SOMstrI;
	DIM * layDim; 
	int * vSquare;
	
	// Cell bodies
	float capE;// = 2.0e-10;
	float capI;// = 10.0e-12;
	float gLeakE;// = 10.0e-9;
	float gLeakI;// = 5.0e-9;
	float VrestE;
	float VrestI;
	float VhyperE;
	float VhyperI;
	float ThreshE;
	float ThreshI;
	float VrevE;
	float VrevI;
	float refract;// = 0.002
	bool adaptation;
	float alphaCa;
	float tauCa;
	float gAHP;
	float VK;
	
	// Synapses (afferent axons)
	float alphaC;// = 0.5;
	float tauC;// = 0.005;
	float alphaD;// = 0.5;
	float tauD;// = 0.009;
	float learnR;// = 0.1;
	float modEf; // alter the strength of Excit f-f synapses
	float tauEE;// = 0.01;
	float Dg_ElE;
	float tauElE;
	float Dg_IE;// = 0.5;
	float tauIE;// = 0.001
	float Dg_EI;// = 0.5;
	float tauEI;// = 0.001;
	float Dg_II;// = 0.5;
	float tauII;// = 0.001;
	float gMax;// = 48.0e-10;
} PARAMS;

//PARAMS * mp;
extern PARAMS * mp;
extern gsl_rng * mSeed;
extern gsl_rng ** states;

#endif
