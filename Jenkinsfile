pipeline {
    agent any
    stages {
        stage('Checkout Main') {
            steps {
                // Checkout the main branch
                git branch: 'main', url: 'https://github.com/bhoomikashirol/Demo-Project-for-Jenkins.git'
            }
        }
        stage('Checkout Code') {
            steps {
                // Checkout the code branch
                script {
                    sh 'git clone -b code https://github.com/bhoomikashirol/Demo-Project-for-Jenkins.git code-branch'
                    sh 'cp code-branch/Code.cpp Demo-Project-for-Jenkins/'
                }
            }
        }
        stage('Checkout Test') {
            steps {
                // Checkout the Test branch
                script {
                    sh 'git clone -b Test https://github.com/bhoomikashirol/Demo-Project-for-Jenkins.git test-branch'
                    sh 'cp test-branch/CodeTest.cpp Demo-Project-for-Jenkins/'
                }
            }
        }
        stage('Clean') {
            steps {
                sh "rm -rf Demo-Project-for-Jenkins/build"
            }
        }
        stage('Build') {
            steps {
                sh """
                mkdir -p Demo-Project-for-Jenkins/build
                cd Demo-Project-for-Jenkins/build
                cmake ..
                make
                """
            }
        }
        stage('Test') {
            steps {
                sh """
                cd Demo-Project-for-Jenkins/build
                ./runTests --gtest_output=xml:test_results.xml
                """
            }
        }
    }
    post {
        always {
            junit 'Demo-Project-for-Jenkins/build/test_results.xml'
        }
    }
}
