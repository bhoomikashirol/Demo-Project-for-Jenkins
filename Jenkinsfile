pipeline {
    agent any
    stages {
        stage('Clean') {
            steps {
                sh 'rm -rf Demo-Project-for-Jenkins'
                sh 'rm -rf code-branch'
                sh 'rm -rf test-branch'
            }
        }
        stage('Checkout') {
            steps {
                sh 'git clone -b main https://github.com/bhoomikashirol/Demo-Project-for-Jenkins.git'
                sh 'git clone -b code https://github.com/bhoomikashirol/Demo-Project-for-Jenkins.git code-branch'
                sh 'git clone -b Test https://github.com/bhoomikashirol/Demo-Project-for-Jenkins.git test-branch'
                sh 'cp code-branch/Code.cpp Demo-Project-for-Jenkins/'
                sh 'cp test-branch/CodeTest.cpp Demo-Project-for-Jenkins/'
            }
        }
        stage('Verify Files') {
            steps {
                sh 'ls -la Demo-Project-for-Jenkins'
            }
        }
        stage('Build') {
            steps {
                sh '''
                    cd Demo-Project-for-Jenkins
                    mkdir -p build
                    cd build
                    cmake ..
                    make
                '''
            }
        }
        stage('Test') {
            steps {
                sh '''
                    cd Demo-Project-for-Jenkins/build
                    ./DemoTest
                '''
            }
        }
    }
}
