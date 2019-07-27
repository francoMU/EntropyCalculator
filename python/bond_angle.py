from ovito.data import *
import numpy as np
from numpy import linalg as LA
from matplotlib import pyplot as plt



def modify(frame, data):

    plt.rc('text', usetex=True)
    plt.rc('font', family='serif')
    plt.title('Bond Angle Distribution')

    binwidth = 0.1
    bins = np.arange(0,180,binwidth)
    angle_hist = np.zeros(len(bins)-1,int)


    topology = data.particles.bonds.topology
    positions = data.particles.positions
    bond_vectors = positions[topology[:,1]] - positions[topology[:,0]]

    cell = data.cell
    bond_vectors += np.dot(cell[:3,:3], data.particles.bonds.pbc_vectors.T).T

    bond_vectors_norm = bond_vectors/np.expand_dims(np.linalg.norm(bond_vectors,axis=1),1)

    bonds_enum = BondsEnumerator(data.particles.bonds)


    for particle_index in range(data.particles.count):
        
        index_bonds = np.fromiter(bonds_enum.bonds_of_particle(particle_index), int)

        local_bonds = bond_vectors_norm[index_bonds]

        angle_matrix = np.squeeze(np.inner(local_bonds[np.newaxis,:,:], 
            local_bonds[:,np.newaxis,:]), axis=(0,3))

        angle_cosines = angle_matrix[np.triu_indices(len(angle_matrix), k=1)]

        degree_angle = np.arccos(angle_cosines)*180/np.pi

        angle_hist += np.histogram(degree_angle, bins=bins)[0]

    angle_hist = angle_hist/np.sum(angle_hist)
    c = np.column_stack((bins[:-1],angle_hist))
    np.savetxt("/home/franco/Paper/Bond_Angle_Distribution/500K.txt",c)
    plt.plot(bins[:-1],angle_hist)
    plt.show()
